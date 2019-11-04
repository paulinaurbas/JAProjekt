
#include "pch.h"
#include "BMPRead.h"


Image::Image(const char* n) : name(n)
{
	FileInfo = new BITMAPFILEHEADER;
	PictureInfo = new BITMAPINFOHEADER;
	Data = makeBitmap(n);
	Data = makeBitmap(n);
}

Image::~Image()
{
}
void Image::CalcBytes()
{
	this->offset = this->FileInfo->bfOffBits;
	this->width = this->PictureInfo->biWidth;
	this->height = this->PictureInfo->biHeight;
}
int Image::GetHeight()
{
	return this->height;
}
int Image::GetWidth()
{
	return this->width;
}
int Image::GetOffSet()
{
	return this->offset;
}
void Image::SetOffSet(int offSet)
{
	this->offset = offSet;
}
void Image::SetWidth(int width)
{
	this->width = width;
}
void Image::SetHeight(int height)
{
	this->height = height;
}
char** Image::getOrginalBMP()
{
	return this->getOrginalBMP();
}
char* Image::makeBitmap(const char* inputName)
{
	std::ifstream iStream(inputName, std::ios::binary);
	if (iStream.good()) {
		char* tempVar = new char[sizeof(BITMAPFILEHEADER)];
		iStream.read(tempVar, sizeof(BITMAPFILEHEADER));
		*FileInfo = *(BITMAPFILEHEADER*)(tempVar);

		tempVar = new char[sizeof(BITMAPINFOHEADER)];
		iStream.read(tempVar, sizeof(BITMAPINFOHEADER));
		*PictureInfo = *(BITMAPINFOHEADER*)(tempVar);

		iStream.seekg(FileInfo->bfOffBits, std::ios::beg);


		int charCount = 3 * PictureInfo->biHeight * PictureInfo->biWidth;
		char* fileData = new char[charCount];

		int countOfPix = PictureInfo->biHeight * PictureInfo->biWidth;
		tempVar = new char[countOfPix * 3];
		iStream.read(tempVar, countOfPix * 3);
		Data = tempVar;
		//char** mapOfPixel = new char*[countOfPix];
		//for (int i = 0; i < countOfPix; i++) {
		//	mapOfPixel[i] = new char[3];
		//}


		iStream.seekg(FileInfo->bfOffBits);
		iStream.read(fileData, charCount * sizeof(char));
		iStream.close();

		int dataIterator = 0;
		/*for (int i = 0; i < countOfPix; i++) {
			for (int j = 0; j < 3; j++) {
				mapOfPixel[i][j] = fileData[dataIterator];
				dataIterator++;
			}
		}
		*/
		width = PictureInfo->biWidth;
		height = PictureInfo->biHeight;
		return Data;
		//return mapOfPixel;
	}
}

/*char** Image::makeBitmap(const char* inputName)
{
	std::ifstream iStream(inputName, std::ios::binary);
	if (iStream.good()) {
		char* tempVar = new char[sizeof(BITMAPFILEHEADER)];
		iStream.read(tempVar, sizeof(BITMAPFILEHEADER));
		*FileInfo = *(BITMAPFILEHEADER*)(tempVar);

		tempVar = new char[sizeof(BITMAPINFOHEADER)];
		iStream.read(tempVar, sizeof(BITMAPINFOHEADER));
		*PictureInfo = *(BITMAPINFOHEADER*)(tempVar);

		iStream.seekg(FileInfo->bfOffBits, std::ios::beg);


		int charCount = 3 * PictureInfo->biHeight * PictureInfo->biWidth;
		char* fileData = new char[charCount];

		int countOfPix = PictureInfo->biHeight * PictureInfo->biWidth;
		tempVar = new char[countOfPix * 3];
		iStream.read(tempVar, countOfPix * 3);
		Data = tempVar;
		//char** mapOfPixel = new char*[countOfPix];
		//for (int i = 0; i < countOfPix; i++) {
		//	mapOfPixel[i] = new char[3];
		//}


		iStream.seekg(FileInfo->bfOffBits);
		iStream.read(fileData, charCount * sizeof(char));
		iStream.close();

		int dataIterator = 0;
		/*for (int i = 0; i < countOfPix; i++) {
			for (int j = 0; j < 3; j++) {
				mapOfPixel[i][j] = fileData[dataIterator];
				dataIterator++;
			}
		}
		*/
		/*width = PictureInfo->biWidth;
		height = PictureInfo->biHeight;

		//return mapOfPixel;
	}
	else {
		return false;
		return NULL;
	}
}*/


void Image::saveBitmap(std::string outputName)
{
	int charCount = 3 * PictureInfo->biHeight * PictureInfo->biWidth;
	char* saveTab = new char[charCount];

	int x = 0;
	for (int i = 0; i < charCount; i++)
	{
		saveTab[x] = Data[i];
	}
		

	std::ofstream oStream(outputName, std::ios::binary);
	oStream.write((char*)FileInfo, sizeof(BITMAPFILEHEADER));
	oStream.write((char*)PictureInfo, sizeof(BITMAPINFOHEADER));

	if (oStream.good()) {
		oStream.write(Data, charCount * sizeof(char));
		oStream.close();
	}

	delete saveTab;
}
