#include "QEquation.h"


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
    int n = 0;
    char dumbBuffer[256] = "";
    while (true){
        n = scanf("%lf %lf %lf", a, b, c);
        if (n != 3){
      	    scanf("%255s/n", dumbBuffer);
        }
        else{
            break;
        }
    }
}

/*!
 * \brief Prints the result of Quadratic Equation.
 * 
 * Function take parameter ans and prints it's meaning.
 * Also that prints roots if they are.
 * \param[in] ans - result of solution.
 * \param[in] x1,x2 - roots
 */

void PrintAnswer(int ans, double x1, double x2){
    assert(!isnan(x1) && !isnan(x2));
    assert(!isfinite(x1) && !isfinite(x2));
    switch (ans){
        case 0:
            printf("equation has no roots\n");
            break;
        case 1:
            printf("equation has the only root: %.4f\n", x1);
            break;
        case 2:
            printf("equation has two roots: %.4f and %.4f\n", x1, x2);
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
 * \brief Checks if double numbers are equal.
 * 
 * Checks if double numbers are equal.
 * \param[in] a,b - number which equality have to be checked.
 * \return Returns true is numbers are equal and false if not.
 */

bool IsEqualDouble(double a, double b){
    assert(!isnan(a) && !isnan(b));
    assert(!isfinite(a) && !isfinite(b));

    static const double EPS = 1E-4;
    return fabs(a - b) < EPS;
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
    assert(!isnan(b) && !isnan(c));
    assert(!isfinite(b) && !isfinite(c));

    if (IsEqualDouble(b, 0.0)){
        if (IsEqualDouble(c, 0.0)){
            return INF_ROOTS;
        }
        else{
            return 0;
        }
    }
    else{
        *x1 = -c / b;
        return 1;
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
    assert(!isnan(a) && !isnan(b) && !isnan(c));
    assert(!isfinite(a) && !isfinite(b) && !isfinite(c));
    
    if (IsEqualDouble(a, 0.0)){
        return SolveLinearEquation(b, c, x1);
    }
    double d = b * b - 4 * a * c;

    if (d < 0){
        return 0;
    }
    if (IsEqualDouble(d, 0.0)){
        *x1 = -b / (2 * a);
        return 1;
    }
    if (d > 0){
        *x1 = (-b - sqrt(d)) / (2 * a);
        *x2 = (-b + sqrt(d)) / (2 * a);
        return 2;
    }
}