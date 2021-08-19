#include <iostream>
#include <math.h>
#define EPS 1E-9

void solveQuadraticEquation(double &a, double &b, double &c){
    if(abs(a)<EPS){
        printf("this is not quadratic equation, linear solution: %.4f", -c/a);
        return;
    }
    double d = b*b-4*a*c;
    if(d < 0){
        printf("equation has no roots");
    }
    if(abs(d)<EPS){
        printf("equation has the only root: %.4lf", (-b)/(2*a));
    }
    if(d > 0){
        printf("equation has two roots: %.4lf and %.4lf", (-b-sqrt(d))/(2*a), (-b+sqrt(d))/(2*a));
    }
}

int main() {
    double a,b,c;
    printf("enter 3 numbers. a,b,c - coefficients of quadratic equation\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    solveQuadraticEquation(a,b,c);
}

