/*  ______________________________________________________________________
 *
 *  ExaDG - High-Order Discontinuous Galerkin for the Exa-Scale
 *
 *  Copyright (C) 2021 by the ExaDG authors
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *  ______________________________________________________________________
 */

#ifndef INCLUDE_EXADG_INCOMPRESSIBLE_NAVIER_STOKES_TIME_INTEGRATION_TIME_INT_BDF_H_
#define INCLUDE_EXADG_INCOMPRESSIBLE_NAVIER_STOKES_TIME_INTEGRATION_TIME_INT_BDF_H_

// deal.II
#include <deal.II/lac/la_parallel_vector.h>

// ExaDG
#include <exadg/time_integration/explicit_runge_kutta.h>
#include <exadg/time_integration/time_int_bdf_base.h>

namespace ExaDG
{
namespace IncNS
{
using namespace dealii;

class InputParameters;

template<int dim, typename Number>
class SpatialOperatorBase;

template<int dim, typename Number>
class OperatorOIF;

template<typename Number>
class PostProcessorInterface;

template<int dim, typename Number>
class TimeIntBDF : public TimeIntBDFBase<Number>
{
public:
  typedef TimeIntBDFBase<Number>                          Base;
  typedef typename Base::VectorType                       VectorType;
  typedef LinearAlgebra::distributed::BlockVector<Number> BlockVectorType;

  typedef SpatialOperatorBase<dim, Number> OperatorBase;

  TimeIntBDF(std::shared_ptr<OperatorBase>                   operator_in,
             InputParameters const &                         param_in,
             unsigned int const                              refine_steps_time_in,
             MPI_Comm const &                                mpi_comm_in,
             bool const                                      is_test_in,
             std::shared_ptr<PostProcessorInterface<Number>> postprocessor_in);

  virtual ~TimeIntBDF()
  {
  }

  virtual VectorType const &
  get_velocity() const = 0;

  virtual VectorType const &
  get_velocity_np() const = 0;

  virtual VectorType const &
  get_pressure_np() const = 0;

  void
  get_velocities_and_times(std::vector<VectorType const *> & velocities,
                           std::vector<double> &             times) const;

  void
  get_velocities_and_times_np(std::vector<VectorType const *> & velocities,
                              std::vector<double> &             times) const;

  void
  ale_update();

  void
  advance_one_timestep_partitioned_solve(bool const use_extrapolation, bool const store_solution);

  virtual void
  print_iterations() const = 0;

  bool
  print_solver_info() const final;

protected:
  void
  allocate_vectors() override;

  void
  setup_derived() override;

  void
  read_restart_vectors(boost::archive::binary_iarchive & ia) override;

  void
  write_restart_vectors(boost::archive::binary_oarchive & oa) const override;

  void
  prepare_vectors_for_next_timestep() override;

  /*
   * This function implements the OIF sub-stepping algorithm. Has to be implemented here
   * since functionality is related to incompressible flows only (nonlinear convective term).
   */
  void
  calculate_sum_alphai_ui_oif_substepping(VectorType & sum_alphai_ui,
                                          double const cfl,
                                          double const cfl_oif) final;

  InputParameters const & param;

  // number of refinement steps, where the time step size is reduced in
  // factors of 2 with each refinement
  unsigned int const refine_steps_time;

  // global cfl number
  double const cfl;

  // cfl number cfl_oif for operator-integration-factor splitting
  double const cfl_oif;

  // spatial discretization operator
  std::shared_ptr<OperatorBase> operator_base;

  // convective term formulated explicitly
  std::vector<VectorType> vec_convective_term;
  VectorType              convective_term_np;

  // required for strongly-coupled partitioned iteration
  bool use_extrapolation;
  bool store_solution;

private:
  void
  initialize_vec_convective_term();

  void
  initialize_oif() final;

  void
  initialize_solution_oif_substepping(VectorType & solution_tilde_m, unsigned int i) final;

  void
  update_sum_alphai_ui_oif_substepping(VectorType &       sum_alphai_ui,
                                       VectorType const & u_tilde_i,
                                       unsigned int       i) final;

  void
  do_timestep_oif_substepping(VectorType & solution_tilde_mp,
                              VectorType & solution_tilde_m,
                              double const start_time,
                              double const time_step_size) final;

  double
  calculate_time_step_size() final;

  double
  recalculate_time_step_size() const final;

  virtual VectorType const &
  get_velocity(unsigned int i /* t_{n-i} */) const = 0;

  virtual VectorType const &
  get_pressure(unsigned int i /* t_{n-i} */) const = 0;

  virtual void
  set_velocity(VectorType const & velocity, unsigned int const i /* t_{n-i} */) = 0;

  virtual void
  set_pressure(VectorType const & pressure, unsigned int const i /* t_{n-i} */) = 0;

  void
  postprocessing() const final;

  // Operator-integration-factor splitting for convective term
  std::shared_ptr<OperatorOIF<dim, Number>> convective_operator_OIF;

  // OIF splitting
  std::shared_ptr<ExplicitTimeIntegrator<OperatorOIF<dim, Number>, VectorType>> time_integrator_OIF;

  // postprocessor
  std::shared_ptr<PostProcessorInterface<Number>> postprocessor;

  // ALE
  VectorType              grid_velocity;
  std::vector<VectorType> vec_grid_coordinates;
  VectorType              grid_coordinates_np;
};

} // namespace IncNS
} // namespace ExaDG

#endif /* INCLUDE_EXADG_INCOMPRESSIBLE_NAVIER_STOKES_TIME_INTEGRATION_TIME_INT_BDF_H_ */
