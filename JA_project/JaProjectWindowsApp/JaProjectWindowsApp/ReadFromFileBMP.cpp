#define _CRT_SECURE_NO_DEPRECATE
#include "stdafx.h"
#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReadFromFileBMP.h"
HEADER * Read_BMP_Header(FILE * inFile, HEADER *pHeader)
{
	fread(&pHeader->Signature, sizeof(pHeader->Signature), 1, inFile);
	fread(&pHeader->Reserved1, sizeof(pHeader->Reserved1), 1, inFile);
	fread(&pHeader->Reserved2, sizeof(pHeader->Reserved2), 1, inFile);
	fread(&pHeader->DataOffSet, sizeof(pHeader->DataOffSet), 1, inFile);
	// Read in info header structure
	return pHeader;
}
INFOHEADER * Read_BMP_Info(FILE * inFile, INFOHEADER * pInfoHeader)
{
	fread(&pInfoHeader->Size, sizeof(pInfoHeader->Size), 1, inFile);
	fread(&pInfoHeader->Width, sizeof(pInfoHeader->Width), 1, inFile);
	fread(&pInfoHeader->Height, sizeof(pInfoHeader->Height), 1, inFile);
	fread(&pInfoHeader->Planes, sizeof(pInfoHeader->Planes), 1, inFile);
	fread(&pInfoHeader->BitsPerPixel, sizeof(pInfoHeader->BitsPerPixel), 1, inFile);
	fread(&pInfoHeader->Compression, sizeof(pInfoHeader->Compression), 1, inFile);
	fread(&pInfoHeader->SizeImage, sizeof(pInfoHeader->SizeImage), 1, inFile);
	fread(&pInfoHeader->XPixelsPreMeter, sizeof(pInfoHeader->XPixelsPreMeter), 1, inFile);
	fread(&pInfoHeader->YPixelsPreMeter, sizeof(pInfoHeader->YPixelsPreMeter), 1, inFile);
	fread(&pInfoHeader->ColorsUsed, sizeof(pInfoHeader->ColorsUsed), 1, inFile);
	fread(&pInfoHeader->ColorsImportant, sizeof(pInfoHeader->ColorsImportant), 1, inFile);
	return pInfoHeader;
}
PIXEL** Read_BMP_Pixel(FILE * inFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		pImage[i] = (PIXEL *)malloc(sizeof(PIXEL) * pInfoHeader->Width);
	}
	// Read in image data to array
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			fread(&pImage[i][j].Red, sizeof(pPixel->Red), 1, inFile);
			fread(&pImage[i][j].Green, sizeof(pPixel->Green), 1, inFile);
			fread(&pImage[i][j].Blue, sizeof(pPixel->Blue), 1, inFile);
			//fread(&pImage[i][j].junk, sizeof(pPixel->junk), 1, inFile);
		}
	}
	return pImage;
}
MyImage * BMPtoImage(char * FileName, MyImage * readyImage)
{
	FILE *inFile;
	readyImage->pHeader = (HEADER *)malloc(sizeof(HEADER));
	readyImage->Info = (INFOHEADER *)malloc(sizeof(INFOHEADER));
	readyImage->tab = (PIXEL *)malloc(sizeof(PIXEL));
	inFile = fopen(FileName, "rb");
	if (inFile == NULL)
	{
		printf("Nie mozna odczytac pliku.\n");

		free(readyImage->pHeader);
		free(readyImage->Info);
		free(readyImage->tab);
		return 0;
	}
	readyImage->pHeader = Read_BMP_Header(inFile, readyImage->pHeader);
	readyImage->Info = Read_BMP_Info(inFile, readyImage->Info);
	readyImage->pPixel = (PIXEL **)malloc(sizeof(PIXEL *) * readyImage->Info->Height);
	readyImage->pCopy = (PIXEL **)malloc(sizeof(PIXEL *) * readyImage->Info->Height);
	readyImage->pPixel = Read_BMP_Pixel(inFile, readyImage->pHeader, readyImage->Info, readyImage->tab, readyImage->pPixel);
	readyImage->pCopy = Read_BMP_Pixel(inFile, readyImage->pHeader, readyImage->Info, readyImage->tab, readyImage->pCopy);
	fclose(inFile);
	return readyImage;

}
void Write_BMP_Header(FILE * outFile, HEADER *pHeader)
{
	fwrite(&pHeader->Signature, sizeof(pHeader->Signature), 1, outFile);
	fwrite(&pHeader->Reserved1, sizeof(pHeader->Reserved1), 1, outFile);
	fwrite(&pHeader->Reserved2, sizeof(pHeader->Reserved2), 1, outFile);
	fwrite(&pHeader->DataOffSet, sizeof(pHeader->DataOffSet), 1, outFile);
}
void Write_BMP_Info(FILE * outFile, INFOHEADER * pInfoHeader)
{
	fwrite(&pInfoHeader->Size, sizeof(pInfoHeader->Size), 1, outFile);
	fwrite(&pInfoHeader->Width, sizeof(pInfoHeader->Width), 1, outFile);
	fwrite(&pInfoHeader->Height, sizeof(pInfoHeader->Height), 1, outFile);
	fwrite(&pInfoHeader->Planes, sizeof(pInfoHeader->Planes), 1, outFile);
	fwrite(&pInfoHeader->BitsPerPixel, sizeof(pInfoHeader->BitsPerPixel), 1, outFile);
	fwrite(&pInfoHeader->Compression, sizeof(pInfoHeader->Compression), 1, outFile);
	fwrite(&pInfoHeader->SizeImage, sizeof(pInfoHeader->SizeImage), 1, outFile);
	fwrite(&pInfoHeader->XPixelsPreMeter, sizeof(pInfoHeader->XPixelsPreMeter), 1, outFile);
	fwrite(&pInfoHeader->YPixelsPreMeter, sizeof(pInfoHeader->YPixelsPreMeter), 1, outFile);
	fwrite(&pInfoHeader->ColorsUsed, sizeof(pInfoHeader->ColorsUsed), 1, outFile);
	fwrite(&pInfoHeader->ColorsImportant, sizeof(pInfoHeader->ColorsImportant), 1, outFile);
}
void Write_BMP_Pixel(FILE * outFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			fwrite(&pImage[i][j].Blue, sizeof(pPixel->Blue), 1, outFile);
			fwrite(&pImage[i][j].Green, sizeof(pPixel->Green), 1, outFile);
			fwrite(&pImage[i][j].Red, sizeof(pPixel->Red), 1, outFile);

		}
	}
}
void WriteBMP(char * FileName, MyImage * pImage)
{
	FILE *outFile;
	outFile = fopen(FileName, "wb");
	if (outFile == NULL)
	{
		printf("Can't open output file for writing.\n");
		return;
	}
	Write_BMP(outFile, pImage->pHeader, pImage->Info, pImage->tab, pImage->pCopy);
	fclose(outFile);
}
void Write_BMP(FILE * outFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage)
{
	Write_BMP_Header(outFile, pHeader);
	Write_BMP_Info(outFile, pInfoHeader);
	Write_BMP_Pixel(outFile, pHeader, pInfoHeader, pPixel, pImage);
}
void DeleteImage(MyImage * pImage)
{
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		free(pImage->pPixel[i]);
	}
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		free(pImage->pCopy[i]);
	}
	free(pImage->pPixel);
	free(pImage->pCopy);
	free(pImage->pHeader);
	free(pImage->Info);
	free(pImage->tab);
}