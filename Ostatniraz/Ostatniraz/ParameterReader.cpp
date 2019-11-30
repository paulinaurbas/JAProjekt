#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include <iostream>
#include "ParamterReader.h"

bool CheckIfNumber(int number)
{
	if (number > 0 && number < 65)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int TerminalCheck(int argc, char * argv[])
{
	if (argc > 1)
	{
		if (argc == 6)
		{
			return 0;
		}
		else if (argc == 8 && strcmp(argv[1], "-i") == 0 && strcmp(argv[3], "-o") == 0)
		{
			if (strcmp(argv[6], "-t") == 0)
			{
				return 2;
			}
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}
void Help()
{
	std::cout << "Pomoc!\n";
	std::cout << "Aby podac nazwe pliku wejsciowego nalezy uzyc komendy -i, a nastepnie podac nazwe pliku wejsciowego \n";
	std::cout << "Aby podac nazwe pliku wyjsciowego nalezy uzyc komendy -o, a nastepnie podac nazwe pliku wyjsciowego \n";
	std::cout << "Aby podac rodzaj przetwarzanego obrazu :\n";
	std::cout << "-1 - C \n";
	std::cout << "-2 - assembler \n";
	std::cout << "Nastepnie -t - oznacza liczbe watkow do prztwarzania, a po przelaczniku liczbe watkow z zakresu 1-64 \n";
	std::cout << "Przykladowe poprawne wywolania programu \n";
	std::cout << "Przykladowe wywolanie -i SwietoHoli.bmp -o Wyjscie \n";
	std::cout << "Przykladowe wywolanie -i SwietoHoli.bmp -o Wyjscie -t 64 \n";
}
bool checkIfExist (const std::string & inputName) {
	if (FILE *file = fopen(inputName.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
