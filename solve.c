#include <math.h>
#include <assert.h>
#include <stddef.h>

void CheckZero(double *a){
    assert(a != NULL);
    static const double EPS = 1E-9;
    if(fabs(*a)<EPS){
        *a = 0.0;
    }
}

int SolveLinearEquation(double b, double c, double *x1){
    if(b == 0.0){
        if(c == 0.0){
            return 3;
        }
        else{
            return 0;
        }
    }
    else{
        *x1 = -c/b;
        return 1;
    }
}

int SolveQuadraticEquation(double a, double b, double c, double *x1, double *x2){
    assert(x1 != NULL);
    assert(x2 != NULL);
    CheckZero(&a);
    CheckZero(&b);
    CheckZero(&c);
    if(a == 0.0){
        return SolveLinearEquation(b,c,x1);
    }
    double d = b*b - 4*a*c;
    CheckZero(&d);
    if(d < 0){
        return 0;
    }
    if(d == 0.0){
        *x1 = -b/(2*a);
        return 1;
    }
    if(d > 0){
        *x1 = (-b - sqrt(d))/(2*a);
        *x2 = (-b + sqrt(d))/(2*a);
        return 2;
    }
}


