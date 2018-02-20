#include <iostream>
#include "../../std_lib_facilities.h"
//#include "StackADT.h"
#include "StackArray.cpp"

int main() {
    string s = "netsket re etteD";
    int i = 100;
    auto *stack = new StackArray<char>(100);

    for (char c : s)
        stack->push(c);

    cout << s << endl;
    while (!stack->isEmpty()) {
        char c = stack->pop();
        cout << c;
    }
    cout << endl;

    return 0;
}