/*
---------------------------------
Kitsou Eftychia - 3120066
Moraitidis Dimitrios - 3100240
---------------------------------
*/

#include "Image.h"
#include <algorithm>
#include "ppm_format.h"
#include <cstring>

using namespace std;

namespace imaging {

	Vec3<float> Image::getPixel(unsigned int x, unsigned int y) const {
		Vec3<float> col;
		col.r = 0;
		col.g = 0;
		col.b = 0;

		if ((x < getWidth() && x >= 0) && (y < getHeight() && y >= 0)) {
			const Vec3<float>& temp = (*this)(x, y);
			col = temp;
		}
		return col;
	}
	void Image::setPixel(unsigned int x, unsigned int y, Vec3<float>& value) {
		if ((x < getWidth() && x >= 0) && (y < getHeight() && y >= 0)) {
			(*this)(x, y) = value;
		}
	}
	void Image::setData(const float * & data_ptr) {
		memcpy(buffer, data_ptr, getWidth() * getHeight() * 3 * sizeof(float));
	}

	Image::Image(unsigned int width, unsigned int height) : Array(width, height) {

	}

	Image::Image(unsigned int width, unsigned int height, const float * data_ptr) : Array(width, height) {
		(*this).setData(data_ptr);
	}

	bool Image::operator << (string filename) {
		Image* img;
		if ((img = ReadPPM(filename.c_str()))) {
			this->height = img->height;
			this->width = img->width;
			this->buffer = img->buffer;
		}
		return img != NULL;
	}

	bool Image::operator >> (string filename) {
		return WritePPM(*this, filename.c_str());
	}

}