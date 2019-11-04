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
	
	char **negative;
	
	int height = 0;
	int width = 0;
	int offset = 0;

public:
	char * Data;
	char** originalBMP;
	BITMAPFILEHEADER* FileInfo;
	BITMAPINFOHEADER* PictureInfo;
	Image(const char* n);
	~Image();
	char** getOrginalBMP();
	int GetHeight();
	int GetWidth();
	int GetOffSet();
	void CalcBytes();
	void SetOffSet(int offSet);
	void SetWidth(int width);
	void SetHeight(int height);
	char * makeBitmap(const char* inputName);
	//** makeBitmap(const char* inputName);
	void saveBitmap(std::string inputName);
};
