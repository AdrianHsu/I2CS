#include <cmath>
#include "BMPImg.h"

using namespace std;

bool BMPImg::loadPic( const string& picPath )
{
	// c_str() is required, since .open receives (char* ,)
    ifstream ifs;
	ifs.open( picPath.c_str(), ios::in|ios::binary );

    // .is_open() return true / false
	if (ifs.is_open()) {

        //sizeof(char) can alternate to headerSize[i]
        for(int i = 0; i < headerNum; i++)
        {
            //char[2] is independent to others
            if(i == 0)
                ifs.read((char*)header.pFlag(i), 2 * sizeof(char));
            // to prevent little Endian problem, judge int / short
            else if(headerSize[i] == 4)
                ifs.read((char*)header.pFlag(i), sizeof(int));
            else if(headerSize[i] == 2)
                ifs.read((char*)header.pFlag(i), sizeof(short));
        }
        //data input, allocate dynamic memory
		data = new unsigned char[header.BitmapDataSize];
        ifs.read((char*)data, header.BitmapDataSize);

	    ifs.close();
	    return true;
	}
	else
	{
		cout << "load BMP image failed." << endl;
		return false;
	}

}
bool BMPImg::storePic( const string& picPath )
{
	ofstream ofs;
	ofs.open( picPath.c_str(), ios::out|ios::binary);
	if(ofs != NULL)
	{
	    //Identifier move to outside the for loop is an alternative way to do that
        ofs.write((char*)header.pFlag(0), 2 * sizeof(char));

        for(int i = 1; i < headerNum; i++)
        {
            if(headerSize[i] == 4)
                ofs.write((char*)header.pFlag(i), sizeof(int));
            if(headerSize[i] == 2)
                ofs.write((char*)header.pFlag(i), sizeof(short));
        }

        ofs.write((char*)data, header.BitmapDataSize);
	    ofs.close();
	    return true;
	}
	else
	{
		cout << "store BMP image failed." << endl;
		return false;
	}
}

bool BMPImg::gammaCorrection(double gamma)
{
	if(data != NULL)
	{
	    //double is required, or it will lose some value
        for (int i = 0 ; i < header.BitmapDataSize ; i++)
            data[i] = (unsigned char)( pow( (double)data[i] / 255 , 1.0 / gamma ) * 255 ) ;
		return true;
	}
	else
		return false;
}
bool BMPImg::sobelEdge()
{
	if(data != NULL)
	{
        //turned all pixel into gray color, stored in temp storage g
        double** g;
        g = new double* [getHeight()];
        //since data stored in 1-D array, we use another variable k to get 1-D data
      	long long int k = 0;
        for(int i = 0; i < getHeight(); i++)
        {
        	g[i] = new double [getWidth()];
        	for(int j = 0; j < getWidth(); j++, k += 3)
        	{
        		//bit map is ordered in BGR, rather than RGB
        		g[i][j] = 0.114 * data[k] + 0.587 * data[k + 1] + 0.299 * data[k + 2];
        	}
        }
        double gx = 0, gy = 0, edge = 0;
        k = 0;
        //x, y prevent  from being -1 and  height/width - 1,
        //since that g[-1][x] or g[y][getWidth()] is undefined
        for(int y = 0; y < getHeight(); y++)
        {
        	for(int x = 0; x < getWidth(); x++, k += 3)
        	{
                //store changed edge value back to data
        	    if(x >= 1 && y >= 1 && x + 1 < getWidth() && y + 1 < getHeight())
                {
                    gx = -g[y - 1][x - 1] - 2 * g[y][x - 1] - g[y + 1][x - 1] + g[y - 1][x + 1] + 2 * g[y][x + 1] + g[y + 1][x + 1];
                    gy = -g[y - 1][x - 1] - 2 * g[y - 1][x] - g[y - 1][x + 1] + g[y + 1][x - 1] + 2 * g[y + 1][x] + g[y + 1][x + 1];
                    edge = sqrt(pow(gx, 2.0) + pow(gy, 2.0));
                }else
                    edge = g[y][x];

        		data[k + 1] = data[k + 2] = data[k] = (unsigned char)edge;
        	}
        }
        //freeing dynamic memory
		for ( int i = 0 ; i < getHeight() ; i++) delete [] g[i] ;
        delete [] g;

		return true;
	}
	else
		return false;
}



