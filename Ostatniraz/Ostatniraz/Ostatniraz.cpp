// Ostatniraz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>

#include "pch.h"
#include <iostream>
extern "C" int _stdcall MyProc1(char* bmp, int begin, int en);
extern "C" void _stdcall Negative(char* bmp, int begin, int end);
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
#include "tchar.h"
#include "BMPRead.h"

void PrintName()
{
	std::cout << "Test" << std::endl;
}

int main(int argc, char * argv[])
{
	Image p1("Holi1.bmp");
	std::vector<std::thread*>threads;
	int currentThreatsSupported = std::thread::hardware_concurrency();
	int threadAmount = currentThreatsSupported;
	int height = p1.GetHeight();
	int width = p1.GetWidth();
	int iterator = 0;
	int * tabwithheight = new int[threadAmount];
	for (int i = 0; i < threadAmount; i++)
	{
		tabwithheight[i] = 0;
	}
	while (height)
	{
		height--;
		tabwithheight[iterator]++;
		iterator == threadAmount - 1 ? iterator = 0 : iterator++;
	}

	/*for (int i = 0; i < threadAmount; i++)
	{
		threads.push_back(new std::thread([=] {
			Negative(p1.Data, i * sizeof(char)*tabwithheight[i]*width, tabwithheight[i] * width);
		}));
	}*/
	
	for (int i = 0; i < threadAmount; i++)
	{
		threads.push_back(new std::thread([=] {
			int currentheight = 0;
			for (int j = 0; j < i; j++)
			{
				currentheight += tabwithheight[j];
			}
			int offset = ((width * 3 * 4) % 3 + width * 3)*currentheight;

			MyProc1(p1.Data+offset, width, tabwithheight[i]);
		}));
	}
	for (int i = 0; i < threadAmount; i++)
	{
		threads[i]->join();
		threads[i] ? delete threads[i],true : false;
		threads[i] = nullptr;
	}

	for (int i = 0; i < threadAmount; i++)
	{
		threads.pop_back();
	}
	p1.saveBitmap("Holi.bmp");


	return 0;


}










