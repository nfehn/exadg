/*
 * q_criterion_calculator.hpp
 *
 *  Created on: Dec 6, 2018
 *      Author: fehn
 */

#ifndef INCLUDE_INCOMPRESSIBLE_NAVIER_STOKES_SPATIAL_DISCRETIZATION_CALCULATORS_Q_CRITERION_CALCULATOR_HPP_
#define INCLUDE_INCOMPRESSIBLE_NAVIER_STOKES_SPATIAL_DISCRETIZATION_CALCULATORS_Q_CRITERION_CALCULATOR_HPP_


#include "q_criterion_calculator.h"

#include <navierstokes/config.h>

namespace IncNS
{
#if DIM_2 && DEGREE_1 && OP_FLOAT
template class QCriterionCalculator<2, 1, float>;
#endif
#if DIM_2 && DEGREE_1 && OP_DOUBLE
template class QCriterionCalculator<2, 1, double>;
#endif

#if DIM_2 && DEGREE_2 && OP_FLOAT
template class QCriterionCalculator<2, 2, float>;
#endif
#if DIM_2 && DEGREE_2 && OP_DOUBLE
template class QCriterionCalculator<2, 2, double>;
#endif

#if DIM_2 && DEGREE_3 && OP_FLOAT
template class QCriterionCalculator<2, 3, float>;
#endif
#if DIM_2 && DEGREE_3 && OP_DOUBLE
template class QCriterionCalculator<2, 3, double>;
#endif

#if DIM_2 && DEGREE_4 && OP_FLOAT
template class QCriterionCalculator<2, 4, float>;
#endif
#if DIM_2 && DEGREE_4 && OP_DOUBLE
template class QCriterionCalculator<2, 4, double>;
#endif

#if DIM_2 && DEGREE_5 && OP_FLOAT
template class QCriterionCalculator<2, 5, float>;
#endif
#if DIM_2 && DEGREE_5 && OP_DOUBLE
template class QCriterionCalculator<2, 5, double>;
#endif

#if DIM_2 && DEGREE_6 && OP_FLOAT
template class QCriterionCalculator<2, 6, float>;
#endif
#if DIM_2 && DEGREE_6 && OP_DOUBLE
template class QCriterionCalculator<2, 6, double>;
#endif

#if DIM_2 && DEGREE_7 && OP_FLOAT
template class QCriterionCalculator<2, 7, float>;
#endif
#if DIM_2 && DEGREE_7 && OP_DOUBLE
template class QCriterionCalculator<2, 7, double>;
#endif

#if DIM_2 && DEGREE_8 && OP_FLOAT
template class QCriterionCalculator<2, 8, float>;
#endif
#if DIM_2 && DEGREE_8 && OP_DOUBLE
template class QCriterionCalculator<2, 8, double>;
#endif

#if DIM_2 && DEGREE_9 && OP_FLOAT
template class QCriterionCalculator<2, 9, float>;
#endif
#if DIM_2 && DEGREE_9 && OP_DOUBLE
template class QCriterionCalculator<2, 9, double>;
#endif

#if DIM_2 && DEGREE_10 && OP_FLOAT
template class QCriterionCalculator<2, 10, float>;
#endif
#if DIM_2 && DEGREE_10 && OP_DOUBLE
template class QCriterionCalculator<2, 10, double>;
#endif

#if DIM_2 && DEGREE_11 && OP_FLOAT
template class QCriterionCalculator<2, 11, float>;
#endif
#if DIM_2 && DEGREE_11 && OP_DOUBLE
template class QCriterionCalculator<2, 11, double>;
#endif

#if DIM_2 && DEGREE_12 && OP_FLOAT
template class QCriterionCalculator<2, 12, float>;
#endif
#if DIM_2 && DEGREE_12 && OP_DOUBLE
template class QCriterionCalculator<2, 12, double>;
#endif

#if DIM_2 && DEGREE_13 && OP_FLOAT
template class QCriterionCalculator<2, 13, float>;
#endif
#if DIM_2 && DEGREE_13 && OP_DOUBLE
template class QCriterionCalculator<2, 13, double>;
#endif

#if DIM_2 && DEGREE_14 && OP_FLOAT
template class QCriterionCalculator<2, 14, float>;
#endif
#if DIM_2 && DEGREE_14 && OP_DOUBLE
template class QCriterionCalculator<2, 14, double>;
#endif

#if DIM_2 && DEGREE_15 && OP_FLOAT
template class QCriterionCalculator<2, 15, float>;
#endif
#if DIM_2 && DEGREE_15 && OP_DOUBLE
template class QCriterionCalculator<2, 15, double>;
#endif

#if DIM_3 && DEGREE_1 && OP_FLOAT
template class QCriterionCalculator<3, 1, float>;
#endif
#if DIM_3 && DEGREE_1 && OP_DOUBLE
template class QCriterionCalculator<3, 1, double>;
#endif

#if DIM_3 && DEGREE_2 && OP_FLOAT
template class QCriterionCalculator<3, 2, float>;
#endif
#if DIM_3 && DEGREE_2 && OP_DOUBLE
template class QCriterionCalculator<3, 2, double>;
#endif

#if DIM_3 && DEGREE_3 && OP_FLOAT
template class QCriterionCalculator<3, 3, float>;
#endif
#if DIM_3 && DEGREE_3 && OP_DOUBLE
template class QCriterionCalculator<3, 3, double>;
#endif

#if DIM_3 && DEGREE_4 && OP_FLOAT
template class QCriterionCalculator<3, 4, float>;
#endif
#if DIM_3 && DEGREE_4 && OP_DOUBLE
template class QCriterionCalculator<3, 4, double>;
#endif

#if DIM_3 && DEGREE_5 && OP_FLOAT
template class QCriterionCalculator<3, 5, float>;
#endif
#if DIM_3 && DEGREE_5 && OP_DOUBLE
template class QCriterionCalculator<3, 5, double>;
#endif

#if DIM_3 && DEGREE_6 && OP_FLOAT
template class QCriterionCalculator<3, 6, float>;
#endif
#if DIM_3 && DEGREE_6 && OP_DOUBLE
template class QCriterionCalculator<3, 6, double>;
#endif

#if DIM_3 && DEGREE_7 && OP_FLOAT
template class QCriterionCalculator<3, 7, float>;
#endif
#if DIM_3 && DEGREE_7 && OP_DOUBLE
template class QCriterionCalculator<3, 7, double>;
#endif

#if DIM_3 && DEGREE_8 && OP_FLOAT
template class QCriterionCalculator<3, 8, float>;
#endif
#if DIM_3 && DEGREE_8 && OP_DOUBLE
template class QCriterionCalculator<3, 8, double>;
#endif

#if DIM_3 && DEGREE_9 && OP_FLOAT
template class QCriterionCalculator<3, 9, float>;
#endif
#if DIM_3 && DEGREE_9 && OP_DOUBLE
template class QCriterionCalculator<3, 9, double>;
#endif

#if DIM_3 && DEGREE_10 && OP_FLOAT
template class QCriterionCalculator<3, 10, float>;
#endif
#if DIM_3 && DEGREE_10 && OP_DOUBLE
template class QCriterionCalculator<3, 10, double>;
#endif

#if DIM_3 && DEGREE_11 && OP_FLOAT
template class QCriterionCalculator<3, 11, float>;
#endif
#if DIM_3 && DEGREE_11 && OP_DOUBLE
template class QCriterionCalculator<3, 11, double>;
#endif

#if DIM_3 && DEGREE_12 && OP_FLOAT
template class QCriterionCalculator<3, 12, float>;
#endif
#if DIM_3 && DEGREE_12 && OP_DOUBLE
template class QCriterionCalculator<3, 12, double>;
#endif

#if DIM_3 && DEGREE_13 && OP_FLOAT
template class QCriterionCalculator<3, 13, float>;
#endif
#if DIM_3 && DEGREE_13 && OP_DOUBLE
template class QCriterionCalculator<3, 13, double>;
#endif

#if DIM_3 && DEGREE_14 && OP_FLOAT
template class QCriterionCalculator<3, 14, float>;
#endif
#if DIM_3 && DEGREE_14 && OP_DOUBLE
template class QCriterionCalculator<3, 14, double>;
#endif

#if DIM_3 && DEGREE_15 && OP_FLOAT
template class QCriterionCalculator<3, 15, float>;
#endif
#if DIM_3 && DEGREE_15 && OP_DOUBLE
template class QCriterionCalculator<3, 15, double>;
#endif

} // namespace IncNS


#endif /* INCLUDE_INCOMPRESSIBLE_NAVIER_STOKES_SPATIAL_DISCRETIZATION_CALCULATORS_Q_CRITERION_CALCULATOR_HPP_ \
        */
