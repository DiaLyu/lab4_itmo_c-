#include <iostream>
#include <string>
#include <Windows.h>
#include "SparseVector.h"
#include "SparseMatrix.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SparseVector<int> s_v1(5);
    s_v1[0] = 1;
    s_v1[3] = 4;
    s_v1.print("Вектор 1");

    SparseVector<int> s_v2(5);
    s_v2[2] = 3;
    s_v2[3] = 5;
    s_v2.print("Вектор 2");

    cout << "\n";

    SparseVector<int> vec3 = s_v1 + s_v2;
    vec3.print("Сумма векторов");

    cout << "\n";

    int scalarProduct = s_v1.scalarProduct(s_v2);
    cout << "Скалярное произведение: " << scalarProduct << endl;

    cout << "\n";

    SparseMatrix<int> mat1(3, 3);
    mat1(0, 0) = 1;
    mat1(1, 1) = 2;
    mat1(2, 2) = 3;
    mat1.print("Матрица 1");

    cout << "\n";

    SparseMatrix<int> mat2(3, 3);
    mat2(0, 2) = 4;
    mat2(1, 0) = 5;
    mat2(2, 1) = 6;
    mat2.print("Матрица 2");

    cout << "\n";

    SparseMatrix<int> mat3 = mat1 + mat2;
    mat3.print("Сумма матриц");

    SparseMatrix<int> transposed = mat1.transpose();
    transposed.print("Транспонированная матрица 1");

    return 0;
}