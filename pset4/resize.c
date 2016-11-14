/**
 * cloned from copy.c
 * 
 * Computer Science 50
 * Problem Set 4
 * by Clariz Mariano
 * Program resizes a bmp by a scale factor by reading it, and copying pixel by pixel.
 */ 
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize size infile outfile\n");
   return 1;
    }

    // remember filenames
    int scalefactor = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // check if multiplier is between 1 and 100
    if (scalefactor < 1 || scalefactor > 100)
    {
        printf("Usage: size must be between 1 and 100\n");
        return 1;
    }

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // set original width and height
    int originalWidth = bi.biWidth;
    int originalHeight = bi.biHeight;

    // update:  bfSize, biHeight, biSizeImage, and biWidth
    bi.biWidth = bi.biWidth* scalefactor;
    bi.biHeight = bi.biHeight*scalefactor;

    // determine padding for scanlines
    int originalPadding =  (4 - (originalWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // contains padding
    bi.biSizeImage = (((bi.biWidth) ) * sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight);
//    bi.biSizeImage = ((abs(bi.biWidth) + padding) * sizeof(RGBTRIPLE) ) * abs(bi.biHeight);

    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // use infile's original width & height to iterate scanlines
    for (int i = 0, biHeight = abs(originalHeight); i < biHeight; i++)
    {
    // for vertical copy
    for (int h = 0; h < scalefactor; h++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < originalWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for (int w = 0; w < scalefactor; w++)
                {
                    
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);



                    
                }
        }
      
        
       // skip over padding in the input file, if any
        fseek(inptr, originalPadding, SEEK_CUR);

        // write padding to the output file, if any
        for (int k = 0; k < padding; k++)
        {

            fputc(0x00, outptr);
        }

     // moves the file position indicator to the start of the line
     // if this is the last horizontal pixel to be duplicated, do not change file pointed 
        if (h < scalefactor-1)
        {
            long int goback = ((originalWidth*sizeof(RGBTRIPLE) + originalPadding));
            fseek(inptr, -goback, SEEK_CUR);
        }
        else {
            continue;
        }
    }
  
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
    
}
