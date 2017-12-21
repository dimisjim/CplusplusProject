

#include "GrayFilter.h"

namespace filtering {

	bool GrayFilter::filter(Image* image) {
		Vec3<float> pixel;
		for (unsigned short i = 0; i < image->getHeight(); i++) {
			for (unsigned short j = 0; j < image->getWidth(); j++) {
				pixel = image->getPixel(j, i);
				float average = (pixel.r + pixel.g + pixel.b) / 3;
				pixel.r = average;
				pixel.g = average;
				pixel.b = average;
				image->setPixel(j, i, pixel);
			}
		}
		return true;
	}

}
