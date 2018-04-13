//
// Created by k on 13.04.18.
//

#ifndef EXERCISE01_ITERATOR_H
#define EXERCISE01_ITERATOR_H


#include <algorithm>
#include <sstream>
#include "IteratorADT.h"

template<class Iterator, class T>
class IteratorImpl : public IteratorADT<Iterator, T> {
public:

    void run(Iterator &it) override;

    IteratorImpl();

    virtual ~IteratorImpl();

private:

    int iteratorSum1(Iterator &it) override;

    int iteratorSum2(Iterator &it) override;

    void sortIterator1(Iterator &it) override;

    void sortIterator2(Iterator &it) override;

    std::string iteratorToString1(Iterator &it) override;

    std::string iteratorToString2(Iterator &it) override;
};

template<class Iterator, class T>
int IteratorImpl<Iterator, T>::iteratorSum1(Iterator &it) {
    int sum = 0;
    for (T e : it)
        sum += e;

    return sum;
}

template<class Iterator, class T>
int IteratorImpl<Iterator, T>::iteratorSum2(Iterator &it) {
    int sum = 0;
    std::for_each(it.begin(), it.end(), [&](T e) { sum += e; });
    return sum;
}

template<class Iterator, class T>
void IteratorImpl<Iterator, T>::sortIterator1(Iterator &it) {
    std::sort(it.begin(), it.end(), IteratorADT<Iterator, T>::compareNumber);
}

template<class Iterator, class T>
void IteratorImpl<Iterator, T>::sortIterator2(Iterator &it) {
    std::sort(it.begin(), it.end(), [](T &a, T &b) {
        return a > b;
    });
}

template<class Iterator, class T>
std::string IteratorImpl<Iterator, T>::iteratorToString1(Iterator &it) {
    std::stringstream ss;
    for (T e : it)
        ss << e << " ";

    return ss.str();
}

template<class Iterator, class T>
std::string IteratorImpl<Iterator, T>::iteratorToString2(Iterator &it) {
    std::stringstream ss;
    std::for_each(it.begin(), it.end(), [&](T &e) {
        ss << e << " ";
    });
    return ss.str();
}

template<class Iterator, class T>
void IteratorImpl<Iterator, T>::run(Iterator &it) {
    std::cout << "Sum = " << iteratorSum1(it) << std::endl;
    std::cout << "Sum = " << iteratorSum2(it) << std::endl;

    Iterator copy1{it};
    std::cout << iteratorToString1(copy1) << std::endl;
    sortIterator1(copy1);
    std::cout << iteratorToString1(copy1) << std::endl;

    Iterator copy2{it};
    std::cout << iteratorToString2(copy2) << std::endl;
    sortIterator2(copy2);
    std::cout << iteratorToString2(copy2) << std::endl;
}

template<class Iterator, class T>
IteratorImpl<Iterator, T>::IteratorImpl() = default;

template<class Iterator, class T>
IteratorImpl<Iterator, T>::~IteratorImpl() = default;


#endif //EXERCISE01_ITERATOR_H
