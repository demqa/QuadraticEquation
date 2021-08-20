#include <math.h>
#include "qe.h"

void SolveQuadraticEquation(double a, double b, double c, double *x1, double *x2, int *ans){
    if(fabs(a)<EPS){
        SolveLinearEquation(b,c,x1,ans);
        return;
    }
    double d = b*b - 4*a*c;
    if(d < 0){
        *ans = 0;
    }
    if(fabs(d)<EPS){
        *ans = 1;
        *x1 = -b/(2*a);
    }
    if(d > 0){
        *ans = 2;
        *x1 = (-b - sqrt(d))/(2*a);
        *x2 = (-b + sqrt(d))/(2*a);
    }
}


void SolveLinearEquation(double b, double c, double *x1, int *ans){
    if(fabs(b)<EPS){
        if(fabs(c)<EPS){
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


