// JAApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/**/
#include "pch.h"/*
#include <windows.h> 
extern "C" int_stdcall MyProc1(DWORD x, DWORD y);
int main()
{
    int x = 3, y = 4, z = 0;

	z = MyProc1(x, y);  // wywo³anie procedury asemblerowej z biblioteki 

	return 0;
}
// JAApp.cpp : Defines the entry point for the console application. 
// 
#include "stdafx.h" */
#include <windows.h>
#include "tchar.h"
/*extern "C" int _stdcall MyProc1(DWORD x, DWORD y);
extern "C" int _stdcall MyProc2 (DWORD x);*/

typedef int(_stdcall *MyProc1)(int, int);
typedef int(_stdcall *MyProc2)(int);

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE dyn_mojadll = LoadLibraryA("JaDll");
	MyProc1 dyn_MyProc1 = (MyProc1)GetProcAddress(dyn_mojadll, "MyProc1");
	MyProc2 dyn_MyProc2 = (MyProc2)GetProcAddress(dyn_mojadll, "MyProc2");

	int x = -2, y = -3, z = 0;
	z = dyn_MyProc1(x, y);
	int a = 3, b = 0;
	//a = dyn_MyProc2(b);
	// wywo³anie procedury asemblerowej z biblioteki
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
