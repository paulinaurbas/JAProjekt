// Ostatniraz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include "pch.h"
#include <iostream>
extern "C" void _stdcall MyProc1(char* bmp, int begin, int en);
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
#include "ParamterReader.h"


int main(int argc, char * argv[])
{
	int terminalnumber = TerminalCheck(argc, argv);
	if (terminalnumber == 1)
	{
		std::cout << "Nie poprawnie podana sciezka" << std::endl;
		Help();
		return 0;
	}

	bool check = checkIfExist(argv[2]);
	if (check == false)
	{
		std::cout << "Nie ma takiego obrazka!" << std::endl;
		Help();
		return 0;
	}

	
	else if (terminalnumber == 0) //domyœlna iloœæ w¹tków
	{
		Image p1(argv[2]);
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
		auto start = std::chrono::high_resolution_clock::now();
			if (strcmp(argv[5], "-1")) //dla C
			{
				for (int i = 0; i < threadAmount; i++)
				{
					threads.push_back(new std::thread([=] {
						Negative(p1.Data, i * sizeof(char)*tabwithheight[i] * width, tabwithheight[i] * width);
					}));
				}
			}
			else //dla ASM
			{
				for (int i = 0; i < threadAmount; i++)
				{
					threads.push_back(new std::thread([=] {
						int currentheight = 0;
						for (int j = 0; j < i; j++)
						{
							currentheight += tabwithheight[j];
						}

						int offset = ((width * 3 * 4) % 3 + width * 3)*currentheight;

						MyProc1(p1.Data + offset, width, tabwithheight[i]);
					}));
				}
			}
		
		for (int i = 0; i < threadAmount; i++)
		{
			threads[i]->join();
			threads[i] ? delete threads[i], true : false;
			threads[i] = nullptr;
		}

		for (int i = 0; i < threadAmount; i++)
		{
			threads.pop_back();
		}
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		int totalTime = duration.count();
		std::cout << "Time is: " << totalTime << std::endl;
		p1.saveBitmap(argv[4]);


	}
	else // iloœæ w¹tków od u¿ytkownika 
	{

		Image p1(argv[2]);
		std::vector<std::thread*>threads;
		int currentThreatsSupported = std::thread::hardware_concurrency();
		int threadAmount = atoi(argv[7]);
		if (!CheckIfNumber(threadAmount))
		{
			std::cout << "Niepoprawna liczba watkow!" << std::endl;
			std::cout << "Liczba watkow powinna byc z zakresu od 1-64!" << std::endl;
		}
		else
		{
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
			std::cout << argv[5] << std::endl;
			auto start = std::chrono::high_resolution_clock::now();
			if (strcmp(argv[5], "-1") == 0) //dla C
			{

				for (int i = 0; i < threadAmount; i++)
				{
					threads.push_back(new std::thread([=] {
						Negative(p1.Data, i * sizeof(char)*tabwithheight[i] * width, tabwithheight[i] * width);
					}));
				}

			}
			else
			{
				for (int i = 0; i < threadAmount; i++)
				{
					threads.push_back(new std::thread([=] {
						int currentheight = 0;
						for (int j = 0; j < i; j++)
						{
							currentheight += tabwithheight[j];
						}

						int offset = ((width * 3 * 4) % 3 + width * 3)*currentheight;

						MyProc1(p1.Data + offset, width, tabwithheight[i]);
					}));
				}
			}

			for (int i = 0; i < threadAmount; i++)
			{
				threads[i]->join();
				threads[i] ? delete threads[i], true : false;
				threads[i] = nullptr;
			}

			for (int i = 0; i < threadAmount; i++)
			{
				threads.pop_back();
			}
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			int totalTime = duration.count();
			std::cout << "Time is: " << totalTime << std::endl;
			p1.saveBitmap(argv[4]);
		}

	}

}










