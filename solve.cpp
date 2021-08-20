#include <stdio.h>
#include <math.h>
#include "qe.h"

void SolveQuadraticEquation(double a, double b, double c){
    if(abs(a)<EPS){
        SolveLinearEquation(b,c);
    }
    double d = b*b - 4*a*c;
    if(d < 0){
        printf("equation has no roots");
    }
    if(abs(d)<EPS){
        printf("equation has the only root: %.4f", (-b)/(2*a));
    }
    if(d > 0){
        printf("equation has two roots: %.4f and %.4f", (-b - sqrt(d))/(2*a), (-b + sqrt(d))/(2*a));
    }
}


void SolveLinearEquation(double b, double c){
	if(abs(b)<EPS){
            if(abs(c)<EPS){
                printf("every real number is a solution of this equation");
            }
            else{
                printf("equation has no roots");
            }
    }
    else{
		printf("this is not quadratic equation, linear solution: %.4f", -c/b);
    }
    return;
}
