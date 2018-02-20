//
// Created by k on 17.02.18.
//

#ifndef OPPGAVE5_STACKARRAY_H
#define OPPGAVE5_STACKARRAY_H

#include "StackADT.h"

template<class T>
class StackArray : public StackADT<T> {
public:

    StackArray() : top(0), stacksize(STDK) {
        stack = new T[STDK];
    }

    explicit StackArray(int size) : top(0), stacksize(size) {
        stack = new T[size];
    }

    ~StackArray() = default;

    void push(T element) override {
        if (size() == stacksize) {
            extend();
        }
        stack[top] = element;
        top++;
    }

    T pop() override {
        T *result = nullptr;
        if (!isEmpty()) {
            top--;
            result = stack + top;
        }
        return *result;
    }

    T *peek() override {
        return isEmpty() ? nullptr : stack + (top - 1);
    };

    bool isEmpty() override {
        return top == 0;
    }

    int size() override {
        return top;
    }

private:
    const int STDK = 100;
    int top;
    T *stack;
    int stacksize;

    void extend() {
        auto *tmp = new T[stacksize * 2];

        for (int i = 0; i < stacksize; i++)
            tmp[i] = stack[i];
        stacksize <<= 1;
        stack = tmp;
    }
};


#endif //OPPGAVE5_STACKARRAY_H
