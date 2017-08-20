/*
---------------------------------
Kitsou Eftychia - 3120066
Moraitidis Dimitrios - 3100240
---------------------------------
*/
#include <map>

using namespace std;

namespace filtering {

	class FilterEnum {

	public:
		enum filter { GRAY = 0, COLOR, BLUR, DIFF };

		FilterEnum() {
			enumMap = map<FilterEnum::filter, const char*>();
			enumMap[FilterEnum::filter::GRAY] = "gray";
			enumMap[FilterEnum::filter::COLOR] = "color";
			enumMap[FilterEnum::filter::BLUR] = "blur";
			enumMap[FilterEnum::filter::DIFF] = "diff";
		}

		const string getStringForEnum(FilterEnum::filter filter) {
			string filterTemp = enumMap[filter];
			return filterTemp;
		}

	private:
		map<FilterEnum::filter, const char*> enumMap;

	};

}
