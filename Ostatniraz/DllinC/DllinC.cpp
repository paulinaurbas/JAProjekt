// DllinC.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DllinC.h"

extern "C"
{
	// Arguments:
	// bmp - address of first byte in bitmap array
	// begin - begin of portion to convert - this must be the beginning of row
	// end - end of portion to convert

	__declspec(dllexport) void Negative(char* bmp, int begin, int end)
	{
		int i;

		for (i = begin*3; i < (begin+end)*3; i+=3)
		{
		
			bmp[i]= 255 - bmp[i];
				bmp[i+1]= 255 - bmp[i+1];
				bmp[i+2]= 255 - bmp[i+2];
		}
		return;
	}
}