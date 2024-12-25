#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

template<typename T>
class SparseVector {
public:
    SparseVector(size_t size) : size_items(size) {}

    T scalarProduct(const SparseVector& another_items) const {
        if (size_items != another_items.size_items) 
            throw invalid_argument("Разные размеры векторов");
        T result = T();
        for (const auto& [index, value] : items) {
            result += value * another_items[index];
        }
        return result;
    }

    T& operator[](size_t index) {
        if (index >= size_items)
            throw out_of_range("Выход за допустимый диапазон");

        return items[index];
    }

    const T operator[](size_t index) const {
        if (index >= size_items)
            throw out_of_range("Выход за допустимый диапазон");

        if (items.find(index) != items.end()) {
            return items.at(index);
        }
        return T();
    }

    SparseVector operator+(const SparseVector& another_items) const {
        if (size_items != another_items.size_items)
            throw invalid_argument("Разные размеры векторов");
        SparseVector result(size_items);
        for (const auto& [index, value] : items) {
            result[index] = value + another_items[index];
        }
        for (const auto& [index, value] : another_items.items) {
            if (items.find(index) == items.end()) {
                result[index] = value;
            }
        }
        return result;
    }

    void print(const string& str = "") const {
        if (!str.empty()) {
            cout << str << ": ";
        }
        for (size_t i = 0; i < size_items; ++i) {
            cout << this->operator[](i) << " ";
        }
        cout << endl;
    }

private:
    unordered_map<size_t, T> items;
    size_t size_items;
};