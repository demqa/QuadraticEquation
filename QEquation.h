#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

void ScanCoefficients(double *a, double *b, double *c);
void PrintAnswer(int ans, double x1, double x2);
int SolveQuadraticEquation(double a, double b, double c, double *x1, double *x2);
bool IsEqualDouble(double a, double b);

const int INF_ROOTS = 3;
