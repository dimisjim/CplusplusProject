
#include "Filter.h"

namespace filtering {

	class ColorFilter : public Filter {

	private:
		Vec3<float> applifier;

	public:
		bool filter(Image* image);
		void setApplifier(Vec3<float> applifier);

	};

}
