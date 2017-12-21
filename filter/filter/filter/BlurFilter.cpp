
#include "BlurFilter.h"

namespace filtering {

	bool BlurFilter::filter(Image* image) {
		Image imageTemp = Image(image->getWidth(), image->getHeight(), (float*)image->getRawDataPtr());
		unsigned short denominator = 0;
		unsigned short x;
		unsigned short y;
		Vec3<float> newPixel = Vec3<float>(0.0f, 0.0f, 0.0f);
		for (unsigned short i = 0; i < imageTemp.getHeight(); i++) {
			for (unsigned short j = 0; j < imageTemp.getWidth(); j++) {
				x = j - 1;
				y = i - 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j - 1, i - 1).r;
					newPixel.g += imageTemp.getPixel(j - 1, i - 1).g;
					newPixel.b += imageTemp.getPixel(j - 1, i - 1).b;
					denominator++;
				}
				x = j - 1;
				y = i;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j - 1, i).r;
					newPixel.g += imageTemp.getPixel(j - 1, i).g;
					newPixel.b += imageTemp.getPixel(j - 1, i).b;
					denominator++;
				}
				x = j - 1;
				y = i + 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j - 1, i + 1).r;
					newPixel.g += imageTemp.getPixel(j - 1, i + 1).g;
					newPixel.b += imageTemp.getPixel(j - 1, i + 1).b;
					denominator++;
				}
				x = j;
				y = i - 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j, i - 1).r;
					newPixel.g += imageTemp.getPixel(j, i - 1).g;
					newPixel.b += imageTemp.getPixel(j, i - 1).b;
					denominator++;
				}
				x = j;
				y = i;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j, i).r;
					newPixel.g += imageTemp.getPixel(j, i).g;
					newPixel.b += imageTemp.getPixel(j, i).b;
					denominator++;
				}
				x = j;
				y = i + 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j, i + 1).r;
					newPixel.g += imageTemp.getPixel(j, i + 1).g;
					newPixel.b += imageTemp.getPixel(j, i + 1).b;
					denominator++;
				}
				x = j + 1;
				y = i - 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j + 1, i - 1).r;
					newPixel.g += imageTemp.getPixel(j + 1, i - 1).g;
					newPixel.b += imageTemp.getPixel(j + 1, i - 1).b;
					denominator++;
				}
				x = j + 1;
				y = i;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j + 1, i).r;
					newPixel.g += imageTemp.getPixel(j + 1, i).g;
					newPixel.b += imageTemp.getPixel(j + 1, i).b;
					denominator++;
				}
				x = j + 1;
				y = i + 1;
				if ((x < imageTemp.getWidth() && x >= 0) && (y < imageTemp.getHeight() && y >= 0)) {
					newPixel.r += imageTemp.getPixel(j + 1, i + 1).r;
					newPixel.g += imageTemp.getPixel(j + 1, i + 1).g;
					newPixel.b += imageTemp.getPixel(j + 1, i + 1).b;
					denominator++;
				}
				newPixel /= denominator;
				image->setPixel(j, i, newPixel);
				denominator = 0;
			}
		}
		return true;
	}

}
