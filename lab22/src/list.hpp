#ifndef __LIST_HPP__
#define __LIST_HPP__

/**
 * @file list.hpp
 * @author Sobolenko S.
 * @brief Модуль з об'явленням контейнеру
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

/* FUNCTOR */

class Functor {
    public:
        bool operator()(int x, int y);
};

bool Functor::operator()(int x, int y) { return x < y; }


/* VECTOR LIST */

class List {
    private:
        std::vector<int> array;

    public:
        List();

        explicit List(int size);

        List(const List& copy);

        ~List();

        void print();

        int getIndex(int item) const;

        void sort();

        int getMin() const;

        void append(const int item);

        void delItem(int pos);

        int getItem(int pos) const;
};


/* CONSTRUCTORS & DESTRUCTOR */

List::List(): array(0) {}

List::List(int size): array(size) {}

List::List(const List& copy): array(0) {
    for (int i = 0; i < this->array.size(); i++) {
        this->array.push_back(copy.array[i]);
    }
}

List::~List() {}


/* OTHER METHODS */

void List::print() {
    if (this->array.size() != 0) {
        for (int i = 0; i < this->array.size() - 1; i++) {
            std::cout << this->array[i] << " ";
        }
            std::cout << this->array[this->array.size() - 1];
    }
}

int List::getIndex(int item) const {
    for (int i = 0; i < this->array.size(); i++) {
        if (this->array[i] == item) {
            return i;
        }
    }
    return -1;
}

void List::sort() {
    std::sort(this->array.begin(), this->array.end(), Functor());
}

int List::getMin() const {
    if (this->array.size() == 0) {
        throw std::out_of_range("Array is empty");
    }

    int min = this->array[0];

    for (int i = 0; i < this->array.size(); i++) {
        if (this->array[i] < min) {
            min = this->array[i];
        }
    }
    return min;
}

void List::append(const int item)
{
    this->array.push_back(item);
}

void List::delItem(int pos)
{
    this->array.erase(this->array.begin() + pos);
}

int List::getItem(int pos) const {
    return this->array[pos];
}

#endif
