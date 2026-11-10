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
    if (lang == "en") {
        cout << "1. help - show the list of commands\n";
        cout << "1.1. create N M - create NxM matrix\n";
        cout << "1.2. resize ID N M - resize matrix ID to size NxM\n";
        cout << "1.3. fill ID {values} - fill matrix[ID]\n";
        cout << "1.4. setval ID X Y VAL - set value in matrix[ID] field X Y\n";
        cout << "1.5. print ID - output the matrix[ID]\n";
        cout << "1.6. delete ID - delete the matrix[ID]\n";
        cout << "1.7. setac VAL - set accuracy to VAL\n";
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
        cout << "4.1. setloc LG - set localization to LG languange (EN, RU, KG)\n";
        cout << "4.2. exit - exit program\n";
        cout << "------------------------------------\n\n";
    } else if (lang == "ru") {
        cout << "1. help - показать список комманд\n";
        cout << "1.1. create N M - создать матрицу размера NxM\n";
        cout << "1.2. resize ID N M - поменять размер матрицы ID на размер NxM\n";
        cout << "1.3. fill ID {values} - заполнить матрицу[ID]\n";
        cout << "1.4. setval ID X Y VAL - задать значение матрицы[ID] поля X Y\n";
        cout << "1.5. print ID - вывести матрицу[ID]\n";
        cout << "1.6. delete ID - удалить матрицу[ID]\n";
        cout << "1.7. setac VAL - установить точность до VAL знаков после запятой\n";
        cout << "------------------------------------\n";
        cout << "2.1. sum ID1 ID2 - посчитать сумму матрицы[ID1] и матрицы[ID2]\n";
        cout << "2.2. sub ID1 ID2 - посчитать разность матрицы[ID1] и матрицы[ID2]\n";
        cout << "2.3. mult ID1 ID2 - посчитать произведение матрицы[ID1] и матрицы[ID2]\n";
        cout << "2.4. pow ID N - посчтитать матрицу[ID] в степени N\n";
        cout << "2.5. push - добавить результат вычисления в конец списка\n";
        cout << "------------------------------------\n";
        cout << "3.1. det ID - посчитать определитель матрицы[ID]\n";
        cout << "3.2. rang ID - почитать ранг матрицы[ID]\n";
        cout << "3.3. inv ID - посчитать обратную матрицу[ID]\n";
        cout << "3.4. tran ID - посчитать транспонированную матрицу[ID]\n";
        cout << "------------------------------------\n";
        cout << "4.1. setloc LG - установить локализацию программы (en, ru, kg)\n";
        cout << "4.2. exit - выйти из программы\n";
        cout << "------------------------------------\n\n";
    } else if (lang == "kg") {
        cout << "1. help - буйруктардын тизмесин көрсөтүү\n";
        cout << "1.1. create N M - NxM өлчөмүндөгү матрица түзүү\n";
        cout << "1.2. resize ID N M - ID матрицасынын өлчөмүн NxM кылып өзгөртүү\n";
        cout << "1.3. fill ID {values} - [ID] матрицасын толтуруу\n";
        cout << "1.4. setval ID X Y VAL - [ID] матрицасынын X Y уячасына маани коюу\n";
        cout << "1.5. print ID - [ID] матрицасын чыгаруу\n";
        cout << "1.6. delete ID - [ID] матрицасын өчүрүү\n";
        cout << "1.7. setac VAL - үтүрдөн кийин VAL белгиге чейин тактыкты коюу\n";
        cout << "------------------------------------\n";
        cout << "2.1. sum ID1 ID2 - [ID1] жана [ID2] матрицаларынын суммасын эсептөө\n";
        cout << "2.2. sub ID1 ID2 - [ID1] жана [ID2] матрицаларынын айырмасын эсептөө\n";
        cout << "2.3. mult ID1 ID2 - [ID1] жана [ID2] матрицаларынын көбөйтүндүсүн эсептөө\n";
        cout << "2.4. pow ID N - [ID] матрицасын N даражасына чыгаруу\n";
        cout << "2.5. push - эсептөөнүн жыйынтыгын тизменин аягына кошуу\n";
        cout << "------------------------------------\n";
        cout << "3.1. det ID - [ID] матрицасынын детерминантын эсептөө\n";
        cout << "3.2. rang ID - [ID] матрицасынын рангын эсептөө\n";
        cout << "3.3. inv ID - [ID] матрицасынын тескери матрицасын эсептөө\n";
        cout << "3.4. tran ID - [ID] матрицасынын транспонирленген матрицасын эсептөө\n";
        cout << "------------------------------------\n";
        cout << "4.1. setloc LG - программанын тилин коюу (en, ru, kg)\n";
        cout << "4.2. exit - программадан чыгуу\n";
        cout << "------------------------------------\n\n";
    }
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

void CmdInv() {
    ll id; cin >> id;
    if (!Good(id)) {
        ThrowError(3);
    } else if (v[id].IsEmpty()) {
        ThrowError(1);
    } else {
        auto [rows, cols] = v[id].GetSize();
        if (rows != cols) {
            ThrowError(5);
        } else {
            if (DetMatrix(v[id]) == 0) {
                ThrowError(8);
            } else {
                cur = InvertedMatrix(v[id]);
                ThrowSuccess(0);
                cur.Print();
            }
        }
    }
}

// Команды 4.X

void CmdSetLocale() {
    string l; cin >> l;
    if (l != "en" && l != "ru" && l != "kg") {
        ThrowError(9);
    } else {
        lang = l;
        ThrowSuccess(0);
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
    else if (cmd == "inv") CmdInv();

    else if (cmd == "setloc") CmdSetLocale();
    else if (cmd == "exit") exit(0);

    else cout << "Unknown command. Type 'help' for help\n\n";
}