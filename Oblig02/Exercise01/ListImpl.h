//
// Created by k on 13.04.18.
//

#ifndef EXERCISE01_LISTIMPL_H
#define EXERCISE01_LISTIMPL_H

#include <algorithm>
#include <sstream>
#include <list>
#include "IteratorADT.h"

template<class Iterator, class T>
class ListImpl {
public:

    void run(Iterator &it) ;

    ListImpl();

    virtual ~ListImpl();

private:

    int listSum1(std::list<T> v);

    int listSum2(std::list<T> v);

    void sortList1(std::list<T> &v);

    void sortList2(std::list<T> &v);

    std::string listToString1(std::list<T> &v);

    std::string listToString2(std::list<T> &v);

};

template<class Iterator, class T>
int ListImpl<Iterator, T>::listSum1(std::list<T> v)  {
    int sum = 0;
    for (T e : v)
        sum += e;
    return sum;
}

template<class Iterator, class T>
int ListImpl<Iterator, T>::listSum2(std::list<T> v) {
    int sum = 0;
    std::for_each(v.begin(), v.end(), [&](T e) { sum += e; });
    return sum;
}

template<class Iterator, class T>
void ListImpl<Iterator, T>::sortList1(std::list<T> &v) {
    v.sort(IteratorADT<Iterator, T>::compareNumber);
}

template<class Iterator, class T>
void ListImpl<Iterator, T>::sortList2(std::list<T> &v) {
    v.sort([](T a, T b) { return a < b; });
}

template<class Iterator, class T>
std::string ListImpl<Iterator, T>::listToString1(std::list<T> &v)  {
    std::stringstream ss;
    for (T e : v) {
        ss << e << " ";
    }
    return ss.str();
}

template<class Iterator, class T>
std::string ListImpl<Iterator, T>::listToString2(std::list<T> &v) {
    std::stringstream ss;
    std::for_each(v.begin(), v.end(), [&](T &e) {
        ss << e << " ";
    });
}

template<class Iterator, class T>
void ListImpl<Iterator, T>::run(Iterator &it) {
    std::cout << "Sum = " << listSum1(it) << std::endl;
    std::cout << "Sum = " << listSum2(it) << std::endl;

    std::list<T> listCopy1{it};
    std::cout << listToString1(listCopy1) << std::endl;
    sortList1(listCopy1);
    std::cout << listToString1(listCopy1) << std::endl;

    std::list<T> listCopy2{it};
    std::cout << listToString2(listCopy2) << std::endl;
    sortList2(listCopy2);
    std::cout << listToString2(listCopy2) << std::endl;
}

template<class Iterator, class T>
ListImpl<Iterator, T>::ListImpl() = default;

template<class Iterator, class T>
ListImpl<Iterator, T>::~ListImpl() = default;

#endif //EXERCISE01_LISTIMPL_H
