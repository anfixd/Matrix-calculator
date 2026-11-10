#include "matrix_ops.h"

#include <algorithm>
#include <vector>

#include "messages.h"

using namespace std;

Matrix SumMatrix(Matrix a, Matrix b) {
    Matrix c;
    auto [an, am] = a.GetSize();
    auto [bn, bm] = b.GetSize();
    ll n = max(an, bn);
    ll m = max(am, bm);
    c.SetSize(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c.SilentSetVal(i, j, a.GetVal(i, j) + b.GetVal(i, j));
        }
    }
    return c;
}

Matrix SubMatrix(Matrix a, Matrix b) {
    Matrix c;
    auto [an, am] = a.GetSize();
    auto [bn, bm] = b.GetSize();
    ll n = max(an, bn);
    ll m = max(am, bm);
    c.SetSize(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c.SilentSetVal(i, j, a.GetVal(i, j) - b.GetVal(i, j));
        }
    }
    return c;
}

Matrix MultMatrix(Matrix a, Matrix b) {
    auto [n, m] = a.GetSize();
    auto [bn, k] = b.GetSize();
    if (m != bn) {
        ThrowError(4);
        return {};
    }
    Matrix c;
    c.SetSize(n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int t = 0; t < m; t++) {
                c.SilentSetVal(i, j, c.GetVal(i, j) + a.GetVal(i, j) * b.GetVal(t, j));
            }
        }
    }
    return c;
}

Matrix EMatrix(ll size) {
    Matrix c;
    c.SetSize(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c.SilentSetVal(i, j, i == j ? 1 : 0);
        }
    }
    return c;
}

Matrix PowMatrix(Matrix a, ll n) {
    if (n == 0) {
        return EMatrix(a.GetSize().first);
    }
    if (n % 2 == 0) {
        return PowMatrix(MultMatrix(a, a), n / 2);
    } else {
        return MultMatrix(PowMatrix(a, n - 1), a);
    }
}

Matrix GetBanned(Matrix b, ll x, ll y) {
    auto [bn, bm] = b.GetSize();
    Matrix res;
    res.SetSize(bn - 1, bm - 1);
    for (int i = 0; i < bn; i++) {
        for (int j = 0; j < bm; j++) {
            if (i == x || j == y) {
                continue;
            }
            res.SilentSetVal(i - (i > x), j - (j > y), b.GetVal(i, j));
        }
    }
    return res;
}

double DetMatrix(Matrix a) {
    ll n = a.GetSize().first;
    if (n == 1) return a.GetVal(0, 0);
    else if (n == 2) return a.GetVal(0, 0) * a.GetVal(1, 1) - a.GetVal(0, 1) * a.GetVal(1, 0);

    double res = 0;

    for (int j = 0; j < n; j++) {
        res += a.GetVal(0, j) * (j % 2 == 0 ? 1 : -1) * DetMatrix(GetBanned(a, 0, j));
    }

    return res;
}

ll RangMatrix(Matrix a) {
    auto [n, m] = a.GetSize();

    for (int f = 0; f < min(n, m); f++) {
        for (int i = f; i < n; i++) {
            for (int j = f; j < m; j++) {
                if (i == f && j >= f) {
                    a.SilentSetVal(i, j, a.GetVal(i, j));
                }
                else if (j == f && i > f) {
                    a.SilentSetVal(i, j, 0);
                }
                else {
                    a.SilentSetVal(i, j, a.GetVal(f, f) * a.GetVal(i, j) - a.GetVal(f, j) * a.GetVal(i, f));
                }
            }
        }
    }

    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a.GetVal(i, j) != 0) {
                used[i] = 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += used[i];
    }

    return ans;
}

Matrix TransposedMatrix(Matrix a) {
    auto [n, m] = a.GetSize();
    Matrix res;
    res.SetSize(m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res.SilentSetVal(j, i, a.GetVal(i, j));
        }
    }
    return res;
}