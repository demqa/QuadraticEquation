#include <iostream>
#include <math.h>
using namespace std;

void solveQuadraticEquation(double &a, double &b, double &c){
    if(a == 0){
        cout << "this is not quadratic equation";
        return;
    }
    double d = b*b-4*a*c;
    if(d < 0){
        cout << "i have to solve this in complex form? for real?";
    }
    if(d == 0){
        cout << "equation has the only root: " <<  -b/(2*a);
    }
    if(d > 0){
        cout << "equation has two roots: " << (-b-sqrt(d))/(2*a) << " and " << (-b+sqrt(d))/(2*a);
    }
}

int main() {
    double a,b,c;
    cin >> a >> b >> c;
    solveQuadraticEquation(a,b,c);
}
