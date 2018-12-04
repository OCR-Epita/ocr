#include <stdio.h>
#include <stdlib.h>

#include "Files/Utility.h"
#include "Files/Traitement.h"
#include "Files/Segmentation.h"
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
    BMPPic_ pic = InitPic(pic,"Images/wiki.bmp");
    BMPPic_ second = InitPic(second,"Images/wiki.bmp");

    /*//pic = DetectOutlines(pic);



    restructPic(pic,"res.bmp");

    free_(pic);*/


    pic = end(pic);
    pic = ApplyRLSA(pic,180,500);

    restructPic(pic,"result/1.bmp");


    pic = Get_Space_Paragraph(pic,second);

    pic = moulinex(pic,second);

    restructPic(second,"result/second.bmp");
    restructPic(pic,"result/result.bmp");

    free_(pic);
	return 0;
}
