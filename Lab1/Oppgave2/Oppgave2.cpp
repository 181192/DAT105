// Oppgave2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../std_lib_facilities.h"

long fakultet(long n)
{
	if (n == 0)
		return 1;
	return (n * fakultet(n - 1));
}

int main()
{
	cout << fakultet(10) << endl;
	return 0;
}

