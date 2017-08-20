/*
---------------------------------
Kitsou Eftychia - 3120066
Moraitidis Dimitrios - 3100240
---------------------------------
*/
#include "Filter.h"
#include <string>

using namespace std;

namespace filtering {

	class GrayFilter : public Filter {

	public:
		bool filter(Image* image);

	};

}