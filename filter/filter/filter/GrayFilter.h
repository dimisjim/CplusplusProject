
#include "Filter.h"
#include <string>

using namespace std;

namespace filtering {

	class GrayFilter : public Filter {

	public:
		bool filter(Image* image);

	};

}
