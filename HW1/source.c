#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct File_Header
{
	unsigned short	bfType;
	unsigned int	bfSize;
	unsigned short	bfReserved1;
	unsigned short	bfReserved2;
	unsigned int	bfOffBits;
}FILEHEADER;

typedef struct Info_Header
{
	unsigned int	biSize;
	int				biWidth;
	int				biHeight;
	unsigned short	biPlanes;
	unsigned short	biBitCount;
	unsigned int	biCompression;
	unsigned int	biSizeImage;
	int				biXPelsPerMeter;
	int 			biYPelsPerMeter;
	unsigned int	biClrUsed;
	unsigned int	biClrImportant;
}INFOHEADER;
typedef  struct tagRGBQUAD
{
	unsigned  char 	rgbBlue;
	unsigned  char 	rgbGreen;
	unsigned  char 	rgbRed;
	unsigned  char 	rgbReserved;
} RGBQUAD;

int main(){
	
	int i = sizeof(FILEHEADER);
	
	FILE *fp;
	FILEHEADER fileheader;
	INFOHEADER info;


if ((fp = fopen("C:\\512_color_lena.bmp","rb")) == NULL) { 
	fprintf(stderr,"file cannot open.");
		return 0;
}
fseek(fp, 0, SEEK_SET);

fread(&fileheader, i, 1, fp);
fread(&info, sizeof(info), 1, fp);
 
printf("ID is %x\n", fileheader.bfType);
printf("file size is %d\n", fileheader.bfSize);
printf("reserved1 is %d\n", fileheader.bfReserved1);
printf("reserved2 is %d\n", fileheader.bfReserved2);
printf("bmp data offset is %d\n", fileheader.bfOffBits);
printf("bmp header size is %d\n", info.biSize);
printf("width is %d\n", info.biWidth);
printf("height is %d\n", info.biHeight);
printf("planes is %d\n", info.biPlanes);
printf("bits per pixel is %d\n", info.biBitCount);
printf("compression is %d\n", info.biCompression);
printf("bmp data size is %d\n", info.biSizeImage);
printf("h resolution is %d\n",  info.biXPelsPerMeter);
printf("V resolution is %d\n", info.biYPelsPerMeter);
printf("used color is %d\n", info.biClrUsed);
printf("important color is %d\n", info.biClrImportant);



fclose(fp);

while (1);

return 0;


}