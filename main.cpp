/*!
\file
\brief main file of program

this file launchs program
*/

#include "QEquation.h"

/*!
\file

this header is only for THIS program.
*/


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
      	    scanf("%255s\n", dumbBuffer);
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
            printf("equation has no roots. But I am GRoot.\n");
            break;
        case ONE_ROOT:
            printf("equation has the only root: %.4lf, and it's me\n", x1);
            break;
        case TWO_ROOTS:
            printf("equation has two roots: %.4lf and %.4lf. Two GRoots? Really?\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("every real number is a solution of this equation. Yo-hoo!!!\n");
            break;
        default:
            printf("there is some error. Keep calm and go out.\n");
            break;
    }
}


/*!
 * \brief Launchs program which solves quadratic equation
 */

int main(){
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    ScanCoefficients(&a, &b, &c);

    int ans = SolveQuadraticEquation(a, b, c, &x1, &x2);
    
    PrintAnswer(ans, x1, x2);
    
    return 0;
}
