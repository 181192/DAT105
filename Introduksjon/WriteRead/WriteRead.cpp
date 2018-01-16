// WriteRead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include <thread>

int main()
{
	if (remove("writeread.txt") != 0){}

	string message = "Daaaamn!";

	ofstream writer("writeread.txt");

	if (! writer)
	{
		cout << "Error opening file" << endl;
		return -1;
	}
	writer << message << endl;
	writer.close();

	ofstream writer2("writeread.txt", ios::app);

	if (!writer2)
	{
		cout << "Error opening file" << endl;
		return -1;
	}
	writer2 << "\n -Steve" << endl;
	writer2.close();

	char letter;

	ifstream reader("writeread.txt");
	if (!reader)
	{
		cout << "Error opening file" << endl;
		return -1;
	}
	for (int i = 0; !reader.eof(); i++)
	{
		reader.get(letter);
		cout << letter;
	}

	cout << endl;
	reader.close();

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	return 0;
}

