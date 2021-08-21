#include <math.h>

void CheckZero(double *a){
    static const double EPS = 1E-9;
    if(fabs(*a)<EPS){
        *a = 0.0;
    }
}

void SolveLinearEquation(double b, double c, double *x1, int *ans){
    if(b == 0.0){
        if(c == 0.0){
            *ans = 3;
        }
        else{
            *ans = 0;
        }
    }
    else{
        *ans = 1;
        *x1 = -c/b;
    }
}

void SolveQuadraticEquation(double a, double b, double c, double *x1, double *x2, int *ans){
    CheckZero(&a);
    CheckZero(&b);
    CheckZero(&c);
    if(a == 0.0){
        SolveLinearEquation(b,c,x1,ans);
        return;
    }
    double d = b*b - 4*a*c;
    CheckZero(&d);
    if(d < 0){
        *ans = 0;
    }
    if(d == 0.0){
        *ans = 1;
        *x1 = -b/(2*a);
    }
    if(d > 0){
        *ans = 2;
        *x1 = (-b - sqrt(d))/(2*a);
        *x2 = (-b + sqrt(d))/(2*a);
    }
}


