/*!
\file

this is header for program
*/

#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

int SolveQuadraticEquation(double a, double b, double c, double *x1, double *x2);
bool IsEqualDouble(double a, double b);

const int INF_ROOTS = 3;
const int TWO_ROOTS = 2;
const int ONE_ROOT = 1;
const int NO_ROOTS = 0;
const int BAD_VALUE = 0xBEDA;
const double EPS = 1E-4;
