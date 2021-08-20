#include <stdio.h>
#include "qe.h"

int main(){
    double a = 0, b = 0, c = 0;
    double x1,x2;
    int ans;
    printf("enter 3 numbers. a,b,c - coefficients of quadratic equation\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    SolveQuadraticEquation(a,b,c,&x1,&x2,&ans);
    if(ans == 0){
        printf("equation has no roots\n");
    }else if(ans == 1){
        printf("equation has the only root: %.4f\n", x1);
    }else if(ans == 2){
        printf("equation has two roots: %.4f and %.4f\n", x1, x2);
    }else if(ans == 3){
        printf("every real number is a solution of this equation\n");
    }
}
