//
// Created by k on 13.04.18.
//

#ifndef EXERCISE01_VECTORADT_H
#define EXERCISE01_VECTORADT_H

#include <iostream>
#include <vector>

template<class Iterator, class T>
class IteratorADT {

public:
    virtual int iteratorSum1(Iterator &it) = 0;

    virtual int iteratorSum2(Iterator &it) = 0;

    virtual void sortIterator1(Iterator &it) = 0;

    virtual void sortIterator2(Iterator &it) = 0;

    virtual std::string iteratorToString1(Iterator &it) = 0;

    virtual std::string iteratorToString2(Iterator &it) = 0;

    virtual void run(Iterator &it) = 0;

    static bool compareNumber(T &a, T &b);

};

template<class Iterator, class T>
bool IteratorADT<Iterator, T>::compareNumber(T &a, T &b) {
    return a < b;
}


#endif //EXERCISE01_VECTORADT_H
