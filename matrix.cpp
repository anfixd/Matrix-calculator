#include "matrix.h"

#include <iomanip>
#include <iostream>

#include "messages.h"

using namespace std;

void Matrix::SetSize(ll n, ll m) {
    N = n;
    M = m;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        V[i].resize(M);
    }
}

void Matrix::Create(ll n, ll m) {
    SetSize(n, m);
    ThrowSuccess(1);
}

void Matrix::Resize(ll n, ll m) {
    SetSize(n, m);
    ThrowSuccess(2);
}

void Matrix::Fill() {
    if (N > 0 && M > 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> V[i][j];
            }
        }
        ThrowSuccess(3);
    } else {
        ThrowError(1);
    }
}

void Matrix::SilentSetVal(ll x, ll y, double val) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        V[x][y] = val;
    }
}

void Matrix::SetVal(ll x, ll y, double val) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        V[x][y] = val;
        ThrowSuccess(4);
    } else {
        ThrowError(2);
    }
}

void Matrix::Print() {
    if (N > 0 && M > 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << setprecision(accuracy) << fixed << V[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    } else {
        ThrowError(3);
    }
}

double Matrix::GetVal(ll x, ll y) {
    if (x < 0 || x >= N || y < 0 || y >= M) {
        return 0.0;
    }
    return V[x][y];
}

bool Matrix::IsEmpty() {
    return N == 0 || M == 0;
}

pair<ll, ll> Matrix::GetSize() {
    return {N, M};
}