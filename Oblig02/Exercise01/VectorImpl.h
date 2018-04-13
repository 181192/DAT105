//
// Created by k on 13.04.18.
//

#ifndef EXERCISE01_VECTORIMP_H
#define EXERCISE01_VECTORIMP_H


#include <algorithm>
#include <sstream>
#include "IteratorADT.h"

template<class Iterator, class T>
class VectorImpl {

public:
    int vectorSum1(std::vector<int> v);

    int vectorSum2(std::vector<int> v);

    void sortVector1(std::vector<T> &v);

    void sortVector2(std::vector<T> &v);

    std::string vectorToString1(std::vector<T> &v);

    std::string vectorToString2(std::vector<T> &v);

    void run(Iterator &it);

    VectorImpl();

    virtual ~VectorImpl();

};

template<class Iterator, class T>
int VectorImpl<Iterator, T>::vectorSum1(std::vector<int> v) {
    int sum = 0;
    for (int e : v)
        sum += e;

    return sum;
}

template<class Iterator, class T>
int VectorImpl<Iterator, T>::vectorSum2(std::vector<int> v) {
    int sum = 0;
    std::for_each(v.begin(), v.end(), [&](T e) { sum += e; });
    return sum;
}

template<class Iterator, class T>
void VectorImpl<Iterator, T>::sortVector1(std::vector<T> &v) {
    std::sort(v.begin(), v.end(), IteratorADT<Iterator, T>::compareNumber);
}

template<class Iterator, class T>
void VectorImpl<Iterator, T>::sortVector2(std::vector<T> &v) {
    std::sort(v.begin(), v.end(), [](T &a, T &b) {
        return a > b;
    });
}

template<class Iterator, class T>
std::string VectorImpl<Iterator, T>::vectorToString1(std::vector<T> &v) {
    std::stringstream ss;
    for (T e : v)
        ss << e << " ";

    return ss.str();
}

template<class Iterator, class T>
std::string VectorImpl<Iterator, T>::vectorToString2(std::vector<T> &v) {
    std::stringstream ss;
    std::for_each(v.begin(), v.end(), [&](T &e) {
        ss << e << " ";
    });
    return ss.str();
}

template<class Iterator, class T>
void VectorImpl<Iterator, T>::run(Iterator &it) {
    std::cout << "Sum = " << vectorSum1(it) << std::endl;
    std::cout << "Sum = " << vectorSum2(it) << std::endl;

    std::vector<T> vectorCopy1{it};
    std::cout << vectorToString1(vectorCopy1) << std::endl;
    sortVector1(vectorCopy1);
    std::cout << vectorToString1(vectorCopy1) << std::endl;

    std::vector<T> vectorCopy2{it};
    std::cout << vectorToString2(vectorCopy2) << std::endl;
    sortVector2(vectorCopy2);
    std::cout << vectorToString2(vectorCopy2) << std::endl;
}

template<class Iterator, class T>
VectorImpl<Iterator, T>::VectorImpl() = default;

template<class Iterator, class T>
VectorImpl<Iterator, T>::~VectorImpl() = default;


#endif //EXERCISE01_VECTORIMP_H
