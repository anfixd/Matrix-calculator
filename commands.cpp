#include "commands.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "matrix.h"
#include "matrix_ops.h"
#include "messages.h"

using namespace std;

namespace {

vector<Matrix> v;
Matrix cur;

bool Good(ll id) {
    return id >= 0 && id < (ll)v.size();
}

void PrintHelp() {
    cout << "1. help - show the list of commands\n";
    cout << "1.1. create N M - create NxM matrix\n";
    cout << "1.2. resize ID N M - resize matrix ID to size NxM\n";
    cout << "1.3. fill ID {values} - fill matrix[ID]\n";
    cout << "1.4. setval ID X Y VAL - set value in matrix[ID] field X Y\n";
    cout << "1.5. print ID - output the matrix[ID]\n";
    cout << "1.6. delete ID - delete thematrix[ID]\n";
    cout << "1.7. setac VAL - Set accuracy to VAL\n";
    cout << "------------------------------------\n";
    cout << "2.1. sum ID1 ID2 - calculate the sum of matrix[ID1] and matrix[ID2]\n";
    cout << "2.2. sub ID1 ID2 - calculate the difference of matrix[ID1] and matrix[ID2]\n";
    cout << "2.3. mult ID1 ID2 - calculate the product of matrix[ID1] and matrix[ID2]\n";
    cout << "2.4. pow ID N - calculate a matrix[ID] raised to the power of N\n";
    cout << "2.5. push - add the current result to the end of the list\n";
    cout << "------------------------------------\n";
    cout << "3.1. det ID - calculate the determinant of a matrix[ID]\n";
    cout << "3.2. rang ID - calculate the rang of a matrix[ID]\n";
    cout << "3.3. inv ID - calculate the inversed matrix[ID]\n";
    cout << "3.4. tran ID - calculate the transposed matrix[ID]\n";
    cout << "------------------------------------\n";
    cout << "4.1. exit - exit program\n";
    cout << "------------------------------------\n\n";
}

// Команды 1.X
void CmdCreate() {
    ll n, m; cin >> n >> m;
    Matrix a;
    a.Create(n, m);
    v.push_back(a);
}

void CmdResize() {
    ll id, n, m; cin >> id >> n >> m;
    if (!Good(id)) ThrowError(3);
    else v[id].Resize(n, m);
}

void CmdFill() {
    ll id; cin >> id;
    if (!Good(id)) ThrowError(3);
    else v[id].Fill();
}

void CmdSetVal() {
    ll id, x, y, val; cin >> id >> x >> y >> val;
    if (!Good(id)) ThrowError(3);
    else v[id].SetVal(x, y, val);
}

void CmdPrint() {
    ll id; cin >> id;
    if (!Good(id)) {
        ThrowError(3);
    } else {
        cout << "\nMatrix " << id << ":\n";
        v[id].Print();
    }
}

void CmdDelete() {
    ll id; cin >> id;
    if (!Good(id)) ThrowError(3);
    else v.erase(v.begin() + id);
}

void CmdSetAccuracy() {
    ll x; cin >> x;
    if (x < 0) {
        ThrowError(7);
    } else {
        accuracy = x;
        ThrowSuccess(6);
    }
}

// Команды 2.X
void CmdSum() {
    ll id1, id2; cin >> id1 >> id2;
    if (!Good(id1) || !Good(id2)) {
        ThrowError(3);
    } else {
        cur = SumMatrix(v[id1], v[id2]);
        ThrowSuccess(0);
        cur.Print();
    }
}

void CmdSub() {
    ll id1, id2; cin >> id1 >> id2;
    if (!Good(id1) || !Good(id2)) {
        ThrowError(3);
    } else {
        cur = SubMatrix(v[id1], v[id2]);
        ThrowSuccess(0);
        cur.Print();
    }
}

void CmdMult() {
    ll id1, id2; cin >> id1 >> id2;
    if (!Good(id1) || !Good(id2)) {
        ThrowError(3);
    } else {
        cur = MultMatrix(v[id1], v[id2]);
        ThrowSuccess(0);
        cur.Print();
    }
}

void CmdPow() {
    ll id, n; cin >> id >> n;
    if (!Good(id) || n < 0) {
        ThrowError(3);
    } else {
        auto [rows, cols] = v[id].GetSize();
        if (rows != cols) {
            ThrowError(5);
        } else {
            cur = PowMatrix(v[id], n);
            ThrowSuccess(0);
            cur.Print();
        }
    }
}

void CmdPush() {
    if (cur.IsEmpty()) {
        ThrowError(6);
    } else {
        v.push_back(cur);
        ThrowSuccess(0);
    }
}

// Команды 3.X
void CmdDet() {
    ll id; cin >> id;
    if (!Good(id)) {
        ThrowError(3);
        return;
    }
    auto [rows, cols] = v[id].GetSize();
    if (rows != cols) {
        ThrowError(5);
    } else {
        cout << setprecision(accuracy) << fixed << DetMatrix(v[id]) << "\n\n";
    }
}

void CmdRang() {
    ll id; cin >> id;
    if (!Good(id)) ThrowError(3);
    else cout << RangMatrix(v[id]) << "\n\n";
}

void CmdTran() {
    ll id; cin >> id;
    if (!Good(id)) {
        ThrowError(3);
    } else if (v[id].IsEmpty()) {
        ThrowError(1);
    } else {
        cur = TransposedMatrix(v[id]);
        cur.Print();
    }
}

} 

void ProcessCommand() {
    string cmd; cin >> cmd;

    if (!cin) exit(0);

    if (cmd == "help") PrintHelp();

    else if (cmd == "create") CmdCreate();
    else if (cmd == "resize") CmdResize();
    else if (cmd == "fill") CmdFill();
    else if (cmd == "setval") CmdSetVal();
    else if (cmd == "print") CmdPrint();
    else if (cmd == "delete") CmdDelete();
    else if (cmd == "setac") CmdSetAccuracy();

    else if (cmd == "sum") CmdSum();
    else if (cmd == "sub") CmdSub();
    else if (cmd == "mult") CmdMult();
    else if (cmd == "pow") CmdPow();
    else if (cmd == "push") CmdPush();

    else if (cmd == "det") CmdDet();
    else if (cmd == "rang") CmdRang();
    else if (cmd == "tran") CmdTran();

    else if (cmd == "exit") exit(0);

    else cout << "Unknown command. Type 'help' for help\n\n";
}