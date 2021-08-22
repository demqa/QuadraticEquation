#include "QEquation.h"

struct Equation{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int ans;
};

void PhraseAns(int ans){
    switch(ans){
        case 0:
            printf("equation has no roots\n");
            break;
	case 1:
            printf("equation has the only root\n");
            break;
	case 2:
            printf("equation has two roots\n");
            break;
	case ANY_VALUE:
            printf("every real number is a solution of this equation\n");
            break;
    }
}

bool Test(struct Equation eq, struct Equation *testEq){
    assert(testEq != NULL);
    double x1 = 0, x2 = 0;

    int ans = SolveQuadraticEquation(eq.a, eq.b, eq.c, &x1, &x2);
    testEq->x1 = x1;
    testEq->x2 = x2;
    testEq->ans = ans;

    switch(ans){
        case 0:
        case 3:
            return eq.ans == ans;
            break;
        case 1:
            return (eq.ans == ans) && Equal(eq.x1,x1);
            break;
        case 2:
            return (eq.ans == ans) && (Equal(eq.x1,x1) && Equal(eq.x2,x2) ||
                                       Equal(eq.x1,x2) && Equal(eq.x2,x1));
            break;
        default:
            return false;
            break;
    }
}


bool TestManager(){
    bool flag = true;
    const struct Equation Tests[8] = {
        {0, 0, 0, 0, 0, ANY_VALUE},
        {1, -5, 6, 3, 2, 2},
        {1, 2, -8, 2, -4, 2},
        {0, 1, 4, -4, 0, 1},
        {0, -2, 8, 4, 0, 1},
        {1, 6, 9, -3, 0, 1},
        {49, -42, 9, 0.4286, 0, 1},
        {1, 5, 100, 0, 0, 0},
    };
    struct Equation testEq = {0};
    for(int i = 1; i <= 8; i++){
        bool result = Test(Tests[i], &testEq);
        if(!result){
            printf("Test №%d is not passed\n", i);
	    printf("a = %.4lf, b = %.4lf, c = %.4lf\n", Tests[i].a, Test[i].b, Tests[i].c);
            printf("answer should be: "); PhraseAns(Tests[i].ans);
            printf("program gives:    "); PhraseAns(testEq.ans);
            printf("roots should be %.4lf, %.4lf\n", Tests[i].x1, Tests[i].x2);
	    printf("program gives   %.4lf, %.4lf\n\n", testEq.x1, testEq.x2);
        }
	testEq.x1 = 0;
	testEq.x2 = 0;
	testEq.ans = 0;
        flag = flag && result;
    }
    return flag;
}

