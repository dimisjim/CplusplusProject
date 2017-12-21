

#include "Vec3.h"
#include "ppm_format.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FilterEnum.h"
#include <queue>
#include "GrayFilter.h"
#include "ColorFilter.h"
#include "BlurFilter.h"
#include "DiffFilter.h"

using namespace filtering;
using namespace std;
using namespace imaging;
using namespace math;

int main(int argc, char* argv[]) {
	string file;
	string filteredFile;
	queue<FilterEnum::filter> ops;
	if (argc < 4) {
		cerr << "You haven't specified enough arguments!";
		return 1;
	}
	file = argv[argc - 1];
	size_t found = file.find("ppm");
	if (found == string::npos) {
		cerr << "You haven't specified a correct .ppm file!" << endl;
		return 2;
	}
	filteredFile = file.substr(0, found - 1) + ".filtered.ppm";
	Image* image = ReadPPM(file.c_str());
	if (image == NULL) {
		cerr << "An error occured. " << endl;
		return 3;
	}
	FilterEnum filterEnum = FilterEnum();
	for (int i = 1; i < argc - 1; i = i + 2) {
		if (!strcmp(argv[i], "-f")) {
			if (filterEnum.getStringForEnum(FilterEnum::filter::GRAY) == argv[i + 1]) {
				GrayFilter grayFilter = GrayFilter();
				grayFilter.filter(image);
			}
			else if (filterEnum.getStringForEnum(FilterEnum::filter::COLOR) == argv[i + 1]) {
				ColorFilter colorFilter = ColorFilter();
				if (strcmp(argv[i + 2], "") && strcmp(argv[i + 3], "") && strcmp(argv[i + 4], "")) {
					Vec3<float> applifier = Vec3<float>((float)atof(argv[i + 2]), (float)atof(argv[i + 3]), (float)atof(argv[i + 4]));
					colorFilter.setApplifier(applifier);
					i = i + 3;
				}
				else {
					cerr << "You do not have specify all the colors for filter color!" << endl;
					return 4;
				}
				colorFilter.filter(image);
			}
			else if (filterEnum.getStringForEnum(FilterEnum::filter::BLUR) == argv[i + 1]) {
				BlurFilter blurFilter = BlurFilter();
				blurFilter.filter(image);
			}
			else if (filterEnum.getStringForEnum(FilterEnum::filter::DIFF) == argv[i + 1]) {
				DiffFilter diffFilter = DiffFilter();
				diffFilter.filter(image);
			}
		}
		else {
			cerr << "You must specify a filter with option -f!" << endl;
			return 5;
		}
	}
	(*image) >> filteredFile;
	return 0;
}
