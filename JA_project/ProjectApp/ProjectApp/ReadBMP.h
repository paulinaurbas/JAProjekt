#pragma once
#include <string>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <chrono> 
#include "pch.h"
class Image {
private:
	const char* name;
	char** originalBMP;
	char ** negative;
	BITMAPFILEHEADER* FileInfo;
	BITMAPINFOHEADER* PictureInfo;
	int height = 0;
	int width = 0;
	int offset = 0;

public:
	Image(const char* n);
	~Image();
	int GetHeight();
	int GetWidth();
	int GetOffSet();
	void CalcBytes();
	char** makeBitmap(const char* inputName);
	void saveBitmap(std::string inputName);
};
