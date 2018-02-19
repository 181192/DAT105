//
// Created by k on 17.02.18.
//

#include "StackArray.h"

template<class T>
void StackArray<T>::push(T element) {
    if (size() == stacksize) {
        extend();
    }
    stack[top] = element;
    top++;
}

template<class T>
T StackArray<T>::pop() {
    T result = nullptr;
    if (!isEmpty()) {
        top--;
        result = stack[top];
        stack[top] = nullptr;
    }
    return result;
}

template<class T>
T StackArray<T>::peek() {
    return isEmpty() ? nullptr : stack[top - 1];
}

template<class T>
bool StackArray<T>::isEmpty() {
    return top == 0;
}

template<class T>
int StackArray<T>::size() {
    return top;
}

template<class T>
StackArray<T>::StackArray() : top(0), stacksize(0) {
    stack = new T[STDK];
}

template<class T>
StackArray<T>::StackArray(int size) : stacksize(size) {
    top = 0;
    stack = new T[size];
}

template<class T>
void StackArray<T>::extend() {
    auto *tmp = new T[stacksize * 2];

    for (int i = 0; i < stacksize; i++)
        tmp[i] = stack[i];

    stack = tmp;
}
