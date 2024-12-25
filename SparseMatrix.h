#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

template<typename T>
class SparseMatrix
{
public:
    SparseMatrix(size_t rows, size_t cols) : rows(rows), cols(cols) {}

    T& operator()(size_t row, size_t col) {
        if (row >= rows || col >= cols) 
            throw out_of_range("Выход за диапазоны");

        return items[row][col];
    }

    const T operator()(size_t row, size_t col) const {
        if (row >= rows || col >= cols) 
            throw out_of_range("Выход за диапазон");

        if (items.find(row) != items.end() && items.at(row).find(col) != items.at(row).end()) {
            return items.at(row).at(col);
        }
        return T();
    }

    SparseMatrix operator+(const SparseMatrix& another_items) const {
        if (rows != another_items.rows || cols != another_items.cols) 
            throw invalid_argument("Количество колонок и столбцв не совпадают");

        SparseMatrix result(rows, cols);
        for (const auto& [row, row_map] : items) {
            for (const auto& [col, value] : row_map) {
                result(row, col) = value + another_items(row, col);
            }
        }
        for (const auto& [row, row_map] : another_items.items) {
            for (const auto& [col, value] : row_map) {
                if (items.find(row) == items.end() || items.at(row).find(col) == items.at(row).end()) {
                    result(row, col) = value;
                }
            }
        }
        return result;
    }

    SparseMatrix transpose() const {
        SparseMatrix result(cols, rows);
        for (const auto& [row, row_map] : items) {
            for (const auto& [col, value] : row_map) {
                result(col, row) = value;
            }
        }
        return result;
    }

    void print(const string& str = "") const {
        if (!str.empty()) {
            cout << str << ":\n";
        }
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << this->operator()(i, j) << " ";
            }
            cout << endl;
        }
    }

private:
    unordered_map<size_t, unordered_map<size_t, T>> items;
    size_t rows, cols;
};