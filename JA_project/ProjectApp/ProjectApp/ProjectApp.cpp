// ProjectApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <windows.h>
#include "tchar.h"
#include "ReadBMP.h"
#include <windows.h>

#include <iostream>
extern "C" int _stdcall MyProc1();
#include <wingdi.h>
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <thread>
#include <string>
#include <list>
#include <algorithm>
void PrintName()
{
	std::cout << "Test" << std::endl;
}
int main(int argc, char * argv[])
{
	Image p1("Holi.bmp");
	p1.saveBitmap("Holi1.bmp");
	unsigned currentThreatsSupported = std::thread::hardware_concurrency();
	int threadAmount = currentThreatsSupported;
	int rowsperthread = p1.GetHeight()/ threadAmount; //ilosc wierszy na watek
	int byteperrow = p1.GetWidth() * 3 + p1.GetWidth() % 4; //ilosc bitow na wiersz
	int bytesperthread = rowsperthread * byteperrow; //ilosc bitow na watek
	int excess = p1.GetHeight() - rowsperthread * threadAmount; //pozostale bity
	int k = 0;
	std::thread ** myThread;
	myThread = new std::thread *[threadAmount];

	for (int i = 0; i < threadAmount; i++)
	{
		int begin = bytesperthread * i + p1.GetOffSet() + k * byteperrow;
		int end = begin + bytesperthread;
		if (excess > 0) //czy zostal jakis wiersz w nadmiarze
		{
			end += byteperrow;
			--excess;
			++k;
		}
		myThread[i] = new std::thread(PrintName);		//tutaj wsadz swoja fukncje

	}
	for (int i = 0; i < threadAmount; i++)
	{
		myThread[i]->join();
	}
	for (int i = 0; i < threadAmount; i++)
	{
		delete myThread[i];

	}
	delete myThread;
	
	MyProc1();

	
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
