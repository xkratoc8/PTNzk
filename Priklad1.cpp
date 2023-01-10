//
// Created by karel on 09.01.2023.
//
#include "Priklad1.h"

template <typename T>
GeneralList<T>::GeneralList() {
    elements = new T[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    size = 0;
}

template <typename T>
void GeneralList<T>::Add(T element, T* prevElement) {
    if (size == capacity) {
        T* newElements = new T[capacity * 2];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity *= 2;
    }

    if (prevElement == nullptr) {
        for (int i = size; i > 0; i--) {
            elements[i] = elements[i - 1];
        }
        elements[0] = element;
    } else {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (&elements[i] == prevElement) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            std::cerr << "Error: Previous element not found in list" << std::endl;
            return;
        }

        for (int i = size; i > index + 1; i--) {
            elements[i] = elements[i - 1];
        }
        elements[index + 1] = element;
    }

    size++;
}

template <typename T>
void GeneralList<T>::Print(std::string (*toString)(T element), std::ofstream& file) {
    for (int i = 0; i < size; i++) {
        file << toString(elements[i]) << std::endl;
    }
}