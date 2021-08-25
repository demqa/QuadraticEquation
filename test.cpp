/*!
\file
\brief test system

this file is a test system for program
*/

#include "QEquation.h"


/*!
 * Structure used for debug program.
 * \param a,b,c - parameters of Quadratic Equation.
 * \param x1,x2 - roots.
 * \param ans - result of solvation
 */

struct Equation{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int ans;
};


/*!
 * \brief Prints the meaning of value ans.
 * 
 * Function take parameter ans and prints it's meaning.
 * \param[in] ans - result of solution.
 */

void PhraseAns(int ans){
    switch (ans){
        case NO_ROOTS:
            printf("equation has no roots\n");
            break;
    	case ONE_ROOT:
            printf("equation has the only root\n");
            break;
    	case TWO_ROOTS:
            printf("equation has two roots\n");
            break;
    	case INF_ROOTS:
            printf("every real number is a solution of this equation\n");
            break;
    }
}

/*!
 * \brief Uses some test to test program.
 * 
 * \param[in] eq - test
 * \param[out] testEq - roots
 * \result true if test passed, and false if not.
 */

bool Test(const struct Equation *eq, struct Equation *testEq){
    assert(testEq != NULL);
    assert(eq != NULL);
    assert(testEq != eq);

    double x1 = NAN, x2 = NAN;

    int ans = SolveQuadraticEquation(eq->a, eq->b, eq->c, &x1, &x2);
    testEq->x1  =  x1;
    testEq->x2  =  x2;
    testEq->ans =  ans;

    switch (ans){
        case NO_ROOTS:
        case INF_ROOTS:
            return eq->ans == ans;
            break;
        case ONE_ROOT:
            return (eq->ans == ans) && IsEqualDouble(eq->x1, x1);
            break;
        case TWO_ROOTS:
            return (eq->ans == ans) &&  (IsEqualDouble(eq->x1, x1) && IsEqualDouble(eq->x2, x2) ||
                                         IsEqualDouble(eq->x1, x2) && IsEqualDouble(eq->x2, x1));
            break;
        default:
            return false;
            break;
    }
}

/*!
 * \brief It manages tests.
 * 
 * Function goes through tests and check if they are passed.
 * Also it prints all information about test and result
 * of program if it wasn't passed.
 * \result true if all tests are passed, false if not.
 */

bool TestManager(){
    bool flag = true;
    const struct Equation tests[] = {
        {0,   0,  0,   0,      0, INF_ROOTS},
        {1,  -5,  6,   3,      2, TWO_ROOTS},
        {1,   2, -8,   2,     -4, TWO_ROOTS},
        {0,   1,  4,  -4,      0, ONE_ROOT},
        {0,  -2,  8,   4,      0, ONE_ROOT},
        {1,   6,  9,  -3,      0, ONE_ROOT},
        {49, -42, 9,   0.4286, 0, ONE_ROOT},
        {1,   5,  100, 0,      0, NO_ROOTS},
    };

    struct Equation testEq = {0};
    for(int i = 0; i < sizeof(tests) / sizeof(Equation); i++){
        bool result = Test(&tests[i], &testEq);
        if (!result){
            printf("Test №%d is not passed\n", i + 1);
            printf("a = %.4lf, b = %.4lf, c = %.4lf\n", tests[i].a, tests[i].b, tests[i].c);
            printf("answer should be: ");   PhraseAns(tests[i].ans);
            printf("program gives:    ");   PhraseAns(testEq.ans);
            printf("roots should be: %.4lf, %.4lf\n", tests[i].x1, tests[i].x2);
            printf("program gives:   %.4lf, %.4lf\n\n", testEq.x1, testEq.x2);
        }
	
    testEq.x1  = NAN;
	testEq.x2  = NAN;
	testEq.ans = BAD_VALUE;

    flag &= result;
    }
    return flag;
}

/*!
 * \brief Launch Test System
 * 
 * Launch Test System and Gives result.
 */

int main(){
    bool result = TestManager();
    if (result){
        printf("program is working well\n");
    }
    else{
        printf("program isn't working correctly\n");
    }
    return 0;
}