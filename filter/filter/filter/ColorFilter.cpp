/*
---------------------------------
Kitsou Eftychia - 3120066
Moraitidis Dimitrios - 3100240
---------------------------------
*/
#include "ColorFilter.h"

namespace filtering {

	bool ColorFilter::filter(Image* image) {
		Vec3<float> pixel;
		for (unsigned short i = 0; i < image->getHeight(); i++) {
			for (unsigned short j = 0; j < image->getWidth(); j++) {
				pixel = image->getPixel(j, i);
				pixel.r = pixel.r * applifier.r;
				pixel.g = pixel.g * applifier.g;
				pixel.b = pixel.b * applifier.b;
				image->setPixel(j, i, pixel);
			}
		}
		return true;
	}

	void ColorFilter::setApplifier(Vec3<float> applifier) {
		this->applifier.r = applifier.r;
		this->applifier.g = applifier.g;
		this->applifier.b = applifier.b;
	}

}