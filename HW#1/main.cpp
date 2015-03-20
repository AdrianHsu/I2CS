#include <iostream>
#include "BMPImg.h"

using namespace std;

int main()
{
	BMPImg img;
	img.loadPic("img/lantern.bmp");
    img.storePic("img/result1.bmp");
	img.gammaCorrection(2.2);
	img.storePic("img/result2.bmp");

	img.loadPic("img/result2.bmp");
	img.sobelEdge();
	img.printHeader();
	img.storePic("img/result3.bmp");
	return 0;
}
