#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date iDag(19, 1, 2018);
    Date *iMorgen = new Date(20, 1, 2018);
    cout << iDag << ' ' << *iMorgen << endl;

    Date nesteDag = iDag + 1;
    cout << iDag << ' ' << nesteDag << endl;
    return 0;
}