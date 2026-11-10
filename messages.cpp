#include "messages.h"

#include <bits/stdc++.h>

using namespace std;

int accuracy = 0;
string lang = "en";

void ThrowError(ll id) {
    if (lang == "en") {
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
            case 9: {cout << "Incorrect languange (en, ru, kg)\n"; break; }

            default: "";
        }
    } else if (lang == "ru") {
        cout << "\nОшибка!\n";
        switch(id) {
            case 1: {cout << "Размер матрицы не задан или матрицы не существует.\n"; break; }
            case 2: {cout << "Выход за пределы или матрицы не существует.\n"; break; }
            case 3: {cout << "Матрицы не существует.\n"; break; }
            case 4: {cout << "Матрицы не могут быть умножены. Некорректные размеры матриц.\n"; break; }
            case 5: {cout << "Матрица не квадратная.\n"; break; }
            case 6: {cout << "Текущий результат пустой.\n"; break; }
            case 7: {cout << "Неверный уровень точности.\n"; break; }
            case 8: {cout << "Определитель матрицы равен 0. Обратной матрицы не существует.\n"; break; }
            case 9: {cout << "Неверный язык (en, ru, kg)\n"; break; }

            default: "";
        }
    } else if (lang == "kg") {
        cout << "\nКата!\n";
        switch(id) {
            case 1: {cout << "Матрицанын өлчөмү көрсөтүлгөн эмес же матрица жок.\n"; break; }
            case 2: {cout << "Чектен тышкары чыгып кетти же матрица жок.\n"; break; }
            case 3: {cout << "Матрица жок.\n"; break; }
            case 4: {cout << "Матрицаларды көбөйтүүгө болбойт. Матрицалардын өлчөмдөрү туура эмес.\n"; break; }
            case 5: {cout << "Матрица чарчы эмес.\n"; break; }
            case 6: {cout << "Учурдагы жыйынтык бош.\n"; break; }
            case 7: {cout << "Тактыктын деңгээли туура эмес.\n"; break; }
            case 8: {cout << "Матрицанын детерминанты 0гө барабар. Тескери матрица жок.\n"; break; }
            case 9: {cout << "Тил туура эмес (en, ru, kg)\n"; break; }

            default: break;
        }
    }
    cout << "\n";
}

void ThrowSuccess(ll id) {
    if (lang == "en") {
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
        } else if (lang == "ru") {
            cout << "\nУспех!\n";
            switch(id) {
                case 1: { cout << "Матрица успешно создана.\n"; break; }
                case 2: { cout << "Размер матрицы задан N×M.\n"; break; }
                case 3: { cout << "Матрица успешно заполнена.\n"; break; }
                case 4: { cout << "Значение успешно задано.\n"; break; }
                case 5: { cout << "Матрица успешно удалена.\n"; break; }
                case 6: { cout << "Уровень точности успешно установлен.\n"; break; }

                default: {""; break;}
            }
        } else if (lang == "kg") {
            cout << "\nИйгиликтүү!\n";
            switch(id) {
                case 1: { cout << "Матрица ийгиликтүү түзүлдү.\n"; break; }
                case 2: { cout << "Матрицанын өлчөмү N×M болуп коюлду.\n"; break; }
                case 3: { cout << "Матрица ийгиликтүү толтурулду.\n"; break; }
                case 4: { cout << "Маани ийгиликтүү коюлду.\n"; break; }
                case 5: { cout << "Матрица ийгиликтүү өчүрүлдү.\n"; break; }
                case 6: { cout << "Тактыктын деңгээли ийгиликтүү коюлду.\n"; break; }

                default: break;
            }
        }
    cout << "\n";
}