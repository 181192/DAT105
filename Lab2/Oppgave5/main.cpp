#include <iostream>
#include "../../std_lib_facilities.h"
#include "StackArray.h"

int main() {
    string s = "netsket re etteD";
    auto *stack = new StackArray<char>();

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