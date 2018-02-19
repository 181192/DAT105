#include <iostream>
#include "../../std_lib_facilities.h"
#include "StackADT.h"
#include "StackArray.h"
#include "Tull.h"

int main() {
    string s = "netsket re etteD";
    int i = 100;

    Tull tull(10);

    StackArray<Tull> stack(100);

    stack.push(tull);

//    for (char c : s)
//        stack.push(c);

//    cout << s << endl;
//    while (!stack.isEmpty()) {
//        char c = stack.pop();
//        cout << c;
//    }
//    cout << endl;

    return 0;
}