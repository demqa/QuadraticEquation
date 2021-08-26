/*!
\file
\brief file with solution

this file contails functions which gives solution
*/

#include "QEquation.h"

/*!
 * \brief Checks if number is zero.
 * 
 * \param[in] a - number that is checking
 * \return Returns true is number is equal to zero
 */

bool IsZero(double a){
    return fabs(a) < EPS;
}


/*!
 * \brief Checks if double numbers are equal.
 * 
 * \param[in] a,b - numbers which equality have to be checked.
 * \return Returns true is numbers are equal and false if not.
 */

bool IsEqualDouble(double a, double b){
    assert(isfinite(a) && isfinite(b));
    return IsZero(a - b);
}


/*!
 * \brief Solves Linear Equation
 * 
 * Solves Linear Equation bx + c = 0
 * \param[in] b,c - coefficients of linear equation
 * \param[out] x1 - root
 * \return number of roots, or constant INF_ROOTS = 3 
 */

int SolveLinearEquation(double b, double c, double *x1){
    assert(x1 != NULL);
    assert(isfinite(b) && isfinite(c));

    if (IsZero(b)){
        if (IsZero(c)){
            return INF_ROOTS;
        }
        return NO_ROOTS;
    }
    *x1 = -c / b;
    return ONE_ROOT;
}


/*!
 * \brief Solves Quadratic Equation
 * 
 * Solves Quadratic Equation ax^2 + bx + c = 0
 * \param[in] a,b,c - coefficients of quadratic equation
 * \param[out] x1,x2 - roots
 * \return answer 
 */

int SolveQuadraticEquation(double a, double b, double c, double *x1, double *x2){
    assert(x1 != NULL && x2 != NULL);
    assert(x1 != x2);
    assert(isfinite(a) && isfinite(b) && isfinite(c));
    
    if (IsZero(a)){
        return SolveLinearEquation(b, c, x1);
    }

    double d = b * b - 4 * a * c;

    if (d < 0){
        return NO_ROOTS;
    }
    if (IsZero(d)){ 
        *x1 = -b / (2 * a);
        return ONE_ROOT;
    }
    if (d > 0){
        *x1 = (-b - sqrt(d)) / (2 * a);
        *x2 = (-b + sqrt(d)) / (2 * a);
        return TWO_ROOTS;
    }
}
