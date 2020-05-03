/*
 * boundary_conditions.h
 *
 *  Created on: 03.05.2020
 *      Author: fehn
 */

#ifndef INCLUDE_STRUCTURE_SPATIAL_DISCRETIZATION_OPERATORS_BOUNDARY_CONDITIONS_H_
#define INCLUDE_STRUCTURE_SPATIAL_DISCRETIZATION_OPERATORS_BOUNDARY_CONDITIONS_H_

#include "../../../functions_and_boundary_conditions/evaluate_functions.h"

#include "../../user_interface/boundary_descriptor.h"

namespace Structure
{
using namespace dealii;

/*
 * This function calculates the Neumann boundary value.
 */
template<int dim, typename Number>
inline DEAL_II_ALWAYS_INLINE //
  Tensor<1, dim, VectorizedArray<Number>>
  calculate_neumann_value(unsigned int const                             q,
                          FaceIntegrator<dim, dim, Number> const &       integrator,
                          BoundaryType const &                           boundary_type,
                          types::boundary_id const                       boundary_id,
                          std::shared_ptr<BoundaryDescriptor<dim>> const boundary_descriptor,
                          double const &                                 time)
{
  Tensor<1, dim, VectorizedArray<Number>> normal_gradient;

  if(boundary_type == BoundaryType::Neumann)
  {
    auto bc       = boundary_descriptor->neumann_bc.find(boundary_id)->second;
    auto q_points = integrator.quadrature_point(q);

    normal_gradient = FunctionEvaluator<1, dim, Number>::value(bc, q_points, time);
  }
  else
  {
    // do nothing

    AssertThrow(boundary_type == BoundaryType::Dirichlet,
                ExcMessage("Boundary type of face is invalid or not implemented."));
  }

  return normal_gradient;
}

} // namespace Structure



#endif /* INCLUDE_STRUCTURE_SPATIAL_DISCRETIZATION_OPERATORS_BOUNDARY_CONDITIONS_H_ */
