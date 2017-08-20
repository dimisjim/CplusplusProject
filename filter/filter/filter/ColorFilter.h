/*
---------------------------------
Kitsou Eftychia - 3120066
Moraitidis Dimitrios - 3100240
---------------------------------
*/
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