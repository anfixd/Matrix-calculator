#include "messages.h"

#include <bits/stdc++.h>

using namespace std;

int accuracy = 0;

void ThrowError(ll id) {
    cout << "\nError!\n";
    switch(id) {
        case 1: {cout << "Matrix size is not specified, or the matrix does not exist.\n"; break; }
        case 2: {cout << "Out of bounds or the matrix does not exist.\n"; break; }
        case 3: {cout << "The matrix does not exist.\n"; break; }
        case 4: {cout << "The matrices cannot be multiplied. Incorrect matrix dimensions.\n"; break; }
        case 5: {cout << "Non-square matrix.\n"; break; }
        case 6: {cout << "Current result is empty.\n"; break; }
        case 7: {cout << "Incorrect accuracy level.\n"; break; }
        case 8: {cout << "The determinant of the matrix is ​​0. The inverse matrix does not exist.\n"; break; }

        default: "";
    }
    cout << "\n";
}

void ThrowSuccess(ll id) {
    cout << "\nSuccess!\n";
    switch(id) {
        case 1: { cout << "Matrix successfuly created.\n"; break; }
        case 2: { cout << "The matrix size is specified as N×M.\n"; break; }
        case 3: { cout << "The matrix has been successfully filled.\n"; break; }
        case 4: { cout << "The value was successfully set.\n"; break; }
        case 5: { cout << "The matrix successfuly deleted.\n"; break; }
        case 6: { cout << "The accuracy successfuly set.\n"; break; }

        default: {""; break;}
    }
    cout << "\n";
}