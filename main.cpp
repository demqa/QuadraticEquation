#include "QEquation.h"


int main(){
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    ScanCoefficients(&a, &b, &c);

    int ans = SolveQuadraticEquation(a, b, c, &x1, &x2);
    
    PrintAnswer(ans, x1, x2);
    
    return 0;
}
