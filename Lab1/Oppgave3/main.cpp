//
// Created by k on 26.02.18.
//

#include "../../std_lib_facilities.h"

vector<int>* primes(int n) {
    auto *primes = new vector<int>();
    primes->push_back(2);
    for (int j = 2; j <= n; ++j) {
        int i = 2;
        for (; i <= j - 1; i++) {
            if (j % i == 0)
                break;
        }
        if (i == j && i != 2)
            primes->push_back(j);
    }
    return primes;
}

int main()
{
    int n;
    cin >> n;

    for (int i : *primes(n))
        cout << i << endl;

    return 0;
}