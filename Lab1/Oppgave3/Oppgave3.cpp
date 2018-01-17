// Oppgave3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../std_lib_facilities.h"


bool* primtall(int n)
{
	bool *prime = new bool[n + 1];
	for (int i = 0; i < n; i++)
		prime[i] = true;
	for (int p = 2; p * p <= n; p++)
		if (prime[p] == true)
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
	return prime;
}

int main()
{
	int n;
	cin >> n;
	bool *prim = primtall(n);
	for (int p = 2; p <= n; p++)
		if (prim[p])
			cout << p << endl;

	return 0;
}
