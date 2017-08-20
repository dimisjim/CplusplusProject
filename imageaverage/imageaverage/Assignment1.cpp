#include "ppm_format.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace imaging;

int main(int argc, char* argv[]) {
	string file;

	if (argc != 2) {
		cout << "File name of the image to load: ";
		getline(cin, file);
	}
	else {
		file = argv[1];
	}

	Image* image = imaging::ReadPPM(file.c_str());
	if (image != NULL) {
		double red = 0, green = 0, blue = 0;
		for (unsigned i = 0; i < image->getWidth(); i++) {
			for (unsigned j = 0; j < image->getHeight(); j++) {
				Color c = image->getPixel(i, j);
				red += c.r;
				green += c.g;
				blue += c.b;
			}
		}
		red /= (image->getWidth() * image->getHeight());
		green /= (image->getWidth() * image->getHeight());
		blue /= (image->getWidth() * image->getHeight());
		cout << "Image dimensions are: " << image->getWidth() << "x" << image->getHeight() << endl;
		cout << "The average color of the image is (" << red << "," << green << "," << blue << ")" << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}