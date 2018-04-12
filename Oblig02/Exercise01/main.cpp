#include <iostream>
#include "../../std_lib_facilities.h"

void printHelloWorld1() {
    cout << "Hello World!" << endl;
}

auto printHelloWorld2 = []() {
    cout << "Hello World2!" << endl;
};

int calculateSum1(int a, int b) {
    return a + b;
}

auto calculateSum2 = [](int a, int b) {
    return a + b;
};

int vectorSum1(vector<int> v) {
    int sum = 0;
    for (int e : v)
        sum += e;

    return sum;
}

int vectorSum2(vector<int> v) {
    int sum = 0;
    for_each(begin(v), end(v), [&](int e) {
        sum += e;
    });
    return sum;
};

template<class T>
bool compareNumber(T &a, T &b) {
    return a > b;
}

template<class T>
void sortVector1(vector<T> &v) {
    sort(v.begin(), v.end(), compareNumber<T>);
}

template<class T>
void sortVector2(vector<T> &v) {
    sort(v.begin(), v.end(), [](T &a, T &b) {
        return a > b;
    });
}

template<class T>
string vectorToString1(vector<T> &v) {
    stringstream ss;
    for (T e : v) {
        ss << e << " ";
    }
    return ss.str();
}

template<class T>
string vectorToString2(vector<T> &v) {
    stringstream ss;
    for_each(v.begin(), v.end(), [&](T &e) {
        ss << e << " ";
    });
}

int main() {
    vector<int> v = {1, 9, 7, 3, 5, 6, 2, 8, 4};

    printHelloWorld1();
    printHelloWorld2();

    cout << "Sum = " << calculateSum1(5, 8) << endl;
    cout << "Sum = " << calculateSum2(5, 8) << endl;
    cout << "Sum = " << vectorSum1(v) << endl;
    cout << "Sum = " << vectorSum2(v) << endl;

    vector<int> vectorCopy1{v};
    cout << vectorToString1(vectorCopy1) << endl;
    sortVector1(vectorCopy1);
    cout << vectorToString1(vectorCopy1) << endl;

    vector<int> vectorCopy2{v};
    cout << vectorToString2(vectorCopy2) << endl;
    sortVector2(vectorCopy2);
    cout << vectorToString2(vectorCopy2) << endl;

    return 0;
}