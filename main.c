#include <stdio.h>
#include <stdlib.h>

#include "Files/Utility.h"
#include "Files/Traitement.h"
#include "Files/Binary.h"

void free_(BMPPic_ pic){
    free(pic.PIXELDATA);
    free(pic.HEADERDATA);
    for (size_t i = 0; i < pic.height; i++) {
        free(pic.GREYMATRIX[i]);
    }
    free(pic.GREYMATRIX);
}

int main()
{
    BMPPic_ pic;

    pic = InitPic(pic, "Images/wiki.bmp");

    pic = end(pic);

    //pic = DetectOutlines(pic);

    pic = ApplyRLSA(pic,300,400);

    restructPic(pic,"res.bmp");


    DetectZones(pic);

    free_(pic);

	return 0;
}
