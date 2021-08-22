#include "QEquation.h"


int main(){
    #ifdef DEBUGMODE  
    bool result = TestManager();
    if(result){
        printf("program is working well\n");
    }else{
        printf("program isn't working correctly\n");
    }
    return 0;
    #endif

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("enter 3 numbers. a,b,c - coefficients of quadratic equation\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    int ans = SolveQuadraticEquation(a, b, c, &x1, &x2);
    switch(ans){
        case 0:
            printf("equation has no roots\n");
            break;
        case 1:
            printf("equation has the only root: %.4f\n", x1);
            break;
        case 2:
            printf("equation has two roots: %.4f and %.4f\n", x1, x2);
            break;
        case ANY_VALUE:
            printf("every real number is a solution of this equation\n");
            break;
        default:
            printf("there is some error\n");
            break;
    }
    return 0;
}
