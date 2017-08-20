#include "Image.h"
#include "Color.h"
#include <algorithm>
#include <cstring>

using namespace std;

namespace imaging
{
	component_t * Image::getRawDataPtr() {
		return buffer;
	}

	Color Image::getPixel(unsigned int x, unsigned int y)const {
		Color col;
		col.r = 0;
		col.g = 0;
		col.b = 0;

		if ((x < getWidth() && x >= 0) && (y < getHeight() && y >= 0)) {
			Color* temp = (Color*)buffer;

			col.r = temp[y * getWidth() + x].r;
			col.g = temp[y * getWidth() + x].g;
			col.b = temp[y * getWidth() + x].b;
		}

		return col;
	}

	void Image::setPixel(unsigned int x, unsigned int y, Color& value) {
		if ((x < getWidth() && x >= 0) && (y < getHeight() && y >= 0)) {
			Color* temp = (Color*)buffer;

			temp[y * getWidth() + x].r = value.r;
			temp[y * getWidth() + x].g = value.g;
			temp[y * getWidth() + x].b = value.b;
		}
	}

	void Image::setData(const component_t* & data_ptr) {
		memcpy(buffer, data_ptr, getWidth() * getHeight() * 3 * sizeof(component_t));
	}

	Image::Image(unsigned int width, unsigned int height) {
		(*this).width = width;
		(*this).height = height;
		(*this).buffer = new component_t[3 * width * height];
	}

	Image::Image(unsigned int width, unsigned int height, const component_t* data_ptr) {
		(*this).width = width;
		(*this).height = height;
		(*this).buffer = new component_t[3 * width * height];
		(*this).setData(data_ptr);
	}

	Image::Image(const Image &src) {
		(*this).width = src.getWidth();
		(*this).height = src.getHeight();
		(*this).buffer = new component_t[3 * width * height];
		(*this).buffer = src.buffer;
	}

	Image::~Image() {
		delete[] buffer;
	}
}



