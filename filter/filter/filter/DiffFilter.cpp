
#include "DiffFilter.h"
#include <vector>
#include <algorithm>

using namespace std;

namespace filtering {

	bool DiffFilter::filter(Image* image) {
		Image imageTemp = Image(image->getWidth(), image->getHeight(), (float*)image->getRawDataPtr());
		unsigned short x;
		unsigned short y;
		Vec3<float> newPixel = Vec3<float>(0.0f, 0.0f, 0.0f);
		vector<float> reds = vector<float>();
		vector<float> greens = vector<float>();
		vector<float> blues = vector<float>();
		for (unsigned short i = 0; i < imageTemp.getHeight(); i++) {
			for (unsigned short j = 0; j < imageTemp.getWidth(); j++) {
				x = j - 1;
				y = i - 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j - 1, i - 1).r);
					greens.push_back(imageTemp.getPixel(j - 1, i - 1).g);
					blues.push_back(imageTemp.getPixel(j - 1, i - 1).b);
				}
				x = j - 1;
				y = i;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j - 1, i).r);
					greens.push_back(imageTemp.getPixel(j - 1, i).g);
					blues.push_back(imageTemp.getPixel(j - 1, i).b);
				}
				x = j - 1;
				y = i + 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j - 1, i + 1).r);
					greens.push_back(imageTemp.getPixel(j - 1, i + 1).g);
					blues.push_back(imageTemp.getPixel(j - 1, i + 1).b);
				}
				x = j;
				y = i - 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j, i - 1).r);
					greens.push_back(imageTemp.getPixel(j, i - 1).g);
					blues.push_back(imageTemp.getPixel(j, i - 1).b);
				}
				x = j;
				y = i;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j, i).r);
					greens.push_back(imageTemp.getPixel(j, i).g);
					blues.push_back(imageTemp.getPixel(j, i).b);
				}
				x = j;
				y = i + 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j, i + 1).r);
					greens.push_back(imageTemp.getPixel(j, i + 1).g);
					blues.push_back(imageTemp.getPixel(j, i + 1).b);
				}
				x = j + 1;
				y = i - 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j + 1, i - 1).r);
					greens.push_back(imageTemp.getPixel(j + 1, i - 1).g);
					blues.push_back(imageTemp.getPixel(j + 1, i - 1).b);
				}
				x = j + 1;
				y = i;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j + 1, i).r);
					greens.push_back(imageTemp.getPixel(j + 1, i).g);
					blues.push_back(imageTemp.getPixel(j + 1, i).b);
				}
				x = j + 1;
				y = i + 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					reds.push_back(imageTemp.getPixel(j + 1, i + 1).r);
					greens.push_back(imageTemp.getPixel(j + 1, i + 1).g);
					blues.push_back(imageTemp.getPixel(j + 1, i + 1).b);
				}
				sort(reds.begin(), reds.end());
				sort(greens.begin(), greens.end());
				sort(blues.begin(), blues.end());
				auto middleRed = next(reds.begin(), reds.size() / 2);
				auto middleGreen = next(greens.begin(), greens.size() / 2);
				auto middleBlue = next(blues.begin(), blues.size() / 2);
				newPixel.r = *middleRed;
				newPixel.g = *middleGreen;
				newPixel.b = *middleBlue;
				image->setPixel(j, i, newPixel);
				reds.empty();
				greens.empty();
				blues.empty();
			}
		}
		return true;
	}

}
