

#include "Vec3.h"
#include "ppm_format.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace imaging;
using namespace math;

int main(int argc, char* argv[]) {
	string file;
	string file2;
	string op;
	bool isCopySpecified = false;

	if (argc < 2) {
		cout << "File name of the image to load: ";
		cin >> file;
	}

	else if (argc < 3) {
		file = argv[1];
	}

	else if (argc < 5) {
		file = argv[1];
		file2 = argv[3];
		op = argv[2];

		if (op == "-o") {
			isCopySpecified = true;
		}
	}

	Image* image = imaging::ReadPPM(file.c_str());
	if (image != NULL) {
		double red = 0, green = 0, blue = 0;
		for (unsigned int i = 0; i < image->getWidth(); i++) {
			for (unsigned int j = 0; j < image->getHeight(); j++) {
				Vec3<float> c = image->getPixel(i, j);
				red += c.r;
				green += c.g;
				blue += c.b;
			}
		}

		red /= (image->getWidth() * image->getHeight());
		green /= (image->getWidth() * image->getHeight());
		blue /= (image->getWidth() * image->getHeight());

		cout << endl;
		cout << file << endl;
		cout << "Image dimensions are: " << image->getWidth() << " x " << image->getHeight() << endl;
		cout << "The average color of the image is (" << red << ", " << green << ", " << blue << ")" << endl;

		if (isCopySpecified) {
			Image* image2 = new Image(0, 0);
			(*image2) << file;
			(*image2) >> file2;
			cout << "Image written to " << file2 << endl;
		}
	}
	else {
		cerr << "An error occured." << endl;
	}
	system("pause");
	return 0;
}
