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
 * \brief Scans Quadratic Equation Coefficients.
 * 
 * Function tells user what to do and scans coefficients.
 * \param[out] a,b,c - parameters of Quadratic Equation.
 */

void ScanCoefficients(double *a, double *b, double *c){
    assert(a != NULL && b != NULL && c != NULL);
    assert(a != b && b != c && a != c);

    printf("enter 3 numbers. a,b,c - coefficients of quadratic equation\n");
    int n = 0, m = 0;
    char dumbBuffer[256] = "";
    while (true){
        n = scanf("%lf %lf %lf", a, b, c);
        if (n != 3){
      	    scanf("%255s/n", dumbBuffer);
            m++;
            if(m == 3){
                printf("you're tired, relax\n");
                exit(1);
            }
        }
        else{
            break;
        }
    }
}

/*!
 * \brief Prints the result of Quadratic Equation.
 * 
 * Function takes parameter ans and prints it's meaning.
 * Also that prints roots if they exist.
 * \param[in] ans - result of solution.
 * \param[in] x1,x2 - roots
 */

void PrintAnswer(int ans, double x1, double x2){
    assert(isfinite(x1) && isfinite(x2));

    switch (ans){
        case NO_ROOTS:
            printf("equation has no roots\n");
            break;
        case ONE_ROOT:
            printf("equation has the only root: %.4lf\n", x1);
            break;
        case TWO_ROOTS:
            printf("equation has two roots: %.4lf and %.4lf\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("every real number is a solution of this equation\n");
            break;
        default:
            printf("there is some error\n");
            break;
    }
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
        else{
            return NO_ROOTS;
        }
    }
    else{
        *x1 = -c / b;
        return ONE_ROOT;
    }
}


/*!
 * \brief Solves Quadratic Equation
 * 
 * Solves Quadratic Equation ax^2 + bx + c = 0
 * \param[in] a,b,c - coefficients of quadratic equation
 * \param[out] x1,x2 - roots
 * \return number of roots, or constant INF_ROOTS = 3 
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