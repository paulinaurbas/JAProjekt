#pragma once
#include "stdafx.h"
#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//24 bity, mo¿e byæ sepia i negatyw 
typedef struct
{
	short Signature;
	long Reserved1;
	long Reserved2;
	long DataOffSet;
} HEADER;
typedef struct
{
	long Size;
	long Width;
	long Height;
	short Planes;
	short BitsPerPixel;
	long Compression;
	long SizeImage;
	long XPixelsPreMeter;
	long YPixelsPreMeter;
	long ColorsUsed;
	long ColorsImportant;
} INFOHEADER;
typedef struct
{
	unsigned char Red, Green, Blue;

} PIXEL;
typedef struct
{
	HEADER *pHeader;
	INFOHEADER * Info;
	PIXEL * tab;
	PIXEL ** pPixel;
	PIXEL ** pCopy;
}MyImage;
/** Function reading in binary from file to structure Header
@author Paulina Urbas
@param inFile, pHeader
@return Header *
*/
HEADER * Read_BMP_Header(FILE * inFile, HEADER *pHeader);
/** Function reading in binary file to structure Infoheader
@author Paulina Urbas
@param inFile, pInfoHeader
@return INFOHEADER *
*/
INFOHEADER * Read_BMP_Info(FILE * inFile, INFOHEADER * pInfoHeader);
/** Function reading PIXELS from file to structure PIXEL **
@author Paulina Urbas
@param inFile, *pHeader, *pInfoHeader, *pPixel, **pImage
@return Header *
*/
PIXEL ** Read_BMP_Pixel(FILE * inFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage);
/**  Function writing structure Header to file
@author Paulina Urbas
@param outFile, *pHeader
*/
void Write_BMP_Header(FILE * outFile, HEADER *pHeader);
/**  Function writing structure InfoHeader o file
@author Paulina Urbas
@param outFile *pInfoHeader
*/
void Write_BMP_Info(FILE * outFile, INFOHEADER * pInfoHeader);
/**  Function writing structure PIXEL to file
@author Paulina Urbas
@param outFile, *pHeader, *pInfoHeader, *pPixel, **pImage
*/
void Write_BMP_Pixel(FILE * outFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage);
/**  Function writing structures Header, InfoHeader, PIXEL to file
@author Paulina Urbas
@param outFile, *pHeader, *pInfoHeader, *pPixel, **pImage
@return PIXEL **
*/
void Write_BMP(FILE * outFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage);
/**  Function reading BMP from file and covering into image
@author Paulina Urbas
@param char *, Image*
@return Image *
*/
MyImage * BMPtoImage(char * FileName, MyImage * readyImage);
/**  Function writing convert BMP to file
@author Paulina Urbas
@param char *, Image*
*/
void WriteBMP(char * FileName, MyImage * pImage);
/**  Function deleting allocated memory for Image
@author Paulina Urbas
@param Image *
*/
void DeleteImage(MyImage * pImage);
