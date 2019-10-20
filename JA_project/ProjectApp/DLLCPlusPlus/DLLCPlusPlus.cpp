// DLLCPlusPlus.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "DLLCPlusPlus.h"

extern "C"
{
	// Function convert 24 - bits bitmap to grayscale
	// It can convert portion of bitmap specified by begin and end(2nd and 3th argument)
	//
	// Arguments:
	// bmp - address of first byte in bitmap array
	// begin - begin of portion to convert - this must be the beginning of row
	// end - end of portion to convert
	// width - width
	__declspec(dllexport)  void Negative(char** bmp, int widht, int height)
	{
		
	}
}