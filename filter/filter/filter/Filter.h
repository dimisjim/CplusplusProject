#ifndef FILTER_H
#define FILTER_H

#include "Image.h"

using namespace imaging;

namespace filtering {

	class Filter {

	public:
		virtual bool filter(Image* image) = 0;

	};

}

#endif FILTER_H