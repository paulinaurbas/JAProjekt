// CPlusPlusDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>

#include "stdafx.h"

#include "CPlusPlusDll.h"

extern "C"
{
	__declspec(dllexport)  void Negative()
	{
		std::cout << "Hello" << std::endl;
	}
}