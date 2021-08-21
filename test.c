#include <math.h>
#include "qe.h"

struct Equation{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int ans;
};

bool Equal(double a, double b){
    static const double accuracy = 1E-4;
    return fabs(a - b)<accuracy;
}

bool Test(struct Equation Eq){
    double x1 = 0,x2 = 0;
    int ans = SolveQuadraticEquation(Eq.a,Eq.b,Eq.c,&x1,&x2);
    switch(ans){
        case 0:
        case 3:
            return Eq.ans == ans;
            break;
        case 1:
            return (Eq.ans == ans) && Equal(Eq.x1,x1);
            break;
        case 2:
            return (Eq.ans == ans) && Equal(Eq.x1,x1) && Equal(Eq.x2,x2);
            break;
        default:
            return false;
            break;
    }
}


bool TestManager(){
    bool flag = true;
    static struct Equation Tests[8] = {
        {0,0,0,0,0,3},
        {1,-5,6,2,3,2},
        {1,2,-8,-4,2,2},
        {0,1,4,-4,0,1},
        {0,-2,8,4,0,1},
        {1,6,9,-3,0,1},
        {49,-42,9,0.4286,0,1},
        {1,5,100,0,0,0},
    };
    for(int i = 0; i<8; i++){
        flag = flag && Test(Tests[i]);
    }
    return flag;
}

