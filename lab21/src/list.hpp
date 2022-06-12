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
#include <stdexcept>
#include <iostream>

/**
 * @brief The list of the <T> type elements
 * 
 * @tparam T 
 */
template <typename T>
class List {
    private:
        int size;
        T *array;

    public:
        List();

        explicit List(int size);

        List(const List& copy);

        ~List();

        /**
         * @brief Print out the list to the consonle
         * 
         */
        void print();

        /**
         * @brief Get the Index of the element, -1 if not exist
         * 
         * @param item 
         * @return int 
         */
        int getIndex(T item) const;

        /**
         * @brief Sort list by ascending
         * 
         */
        void sort();

        /**
         * @brief Get the Min element, error if list is empty
         * 
         * @return T 
         */
        T getMin() const;

        /**
         * @brief Add element to the end of the list
         * 
         * @param item 
         */
        void append(const T& item);

        /**
         * @brief Delete element on the given position
         * 
         * @param pos 
         */
        void delItem(int pos);

        /**
         * @brief Get the Item on the given position
         * 
         * @param pos 
         * @return T 
         */
        T getItem(int pos) const;
};


/* CONSTRUCTORS & DESTRUCTOR */

template <typename T>
List<T>::List(): size(0) {
    this->array = new  T[0];
}

template <typename T>
List<T>::List(int size): size(size) {
    this->array = new T[size];
}

template <typename T>
List<T>::List(const List& copy): size(copy.size) {
    delete [] this->array;
    this->array = copy.array;
}

template <typename T>
List<T>::~List() {
    delete [] this->array;
}


/* OTHER METHODS */

template <typename T>
void List<T>::print() {
    for (int i = 0; i < this->size - 1; i++) {
        std::cout << this->array[i] << " ";
    }
    std::cout << this->array[this->size - 1];
}

template <typename T>
int List<T>::getIndex(T item) const {
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] == item) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void List<T>::sort() {
    for (int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size - i - 1; j++) {
            if (this->array[j] > this->array[j + 1]) {
                T temp = this->array[j];

                this->array[j] = this->array[j + 1];
                this->array[j + 1] = temp;
            }
        }
    }
}

template <typename T>
T List<T>::getMin() const {
    if (this->size == 0) {
        throw std::out_of_range("Array is empty");
    }

    T min = this->array[0];

    for (int i = 0; i < this->size; i++) {
        if (this->array[i] < min) {
            min = this->array[i];
        }
    }

    return min;
}

template <typename T>
void List<T>::append(const T& item)
{
    T *newArray = new T[(unsigned)this->size + 1];

    for (int i = 0; i < this->size; i++) {
        newArray[i] = this->array[i];
    }
    newArray[this->size] = item;

    delete [] this->array;
    this->array = newArray;
    this->size++;
}

template <typename T>
void List<T>::delItem(int pos)
{
    T *newArray = new T[(unsigned)this->size - 1];

    for (int i = 0; i < pos; i++) {
        newArray[i] = this->array[i];
    }
    for (int i = pos + 1; i < this->size; i++) {
        newArray[i - 1] = this->array[i];
    }

    delete [] this->array;
    this->array = newArray;
    this->size--;
}


template <typename T>
T List<T>::getItem(int pos) const {
    return this->array[pos];
}

#endif
