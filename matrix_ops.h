#pragma once

#include "matrix.h"
#include "types.h"

Matrix SumMatrix(Matrix a, Matrix b);
Matrix SubMatrix(Matrix a, Matrix b);
Matrix MultMatrix(Matrix a, Matrix b);
Matrix EMatrix(ll size);
Matrix PowMatrix(Matrix a, ll n);
Matrix GetBanned(Matrix b, ll x, ll y);
double DetMatrix(Matrix a);
ll RangMatrix(Matrix a);
Matrix TransposedMatrix(Matrix a);