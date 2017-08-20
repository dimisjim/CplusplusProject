#include "ppm_format.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <istream>
#include <vector>
#include <cstring>

using namespace std;
using namespace imaging;

int mystoi(string data) {
	return atoi(data.c_str());
}

namespace imaging {
	vector<string> split(const char *str, char c = ' ') {
		vector<string> res;

		do {
			const char *begin = str;
			while (*str != c && *str)
				str++;
			res.push_back(string(begin, str));
		} while (0 != *str++);
		return res;
	}

	char* stringToChar(string &str) {
		char * charstr = new char[str.length() + 1];
		strcpy(charstr, str.c_str());
		return charstr;
	}

	Image* ReadPPM(const char* filename) {
		ifstream file(filename, ios_base::binary);
		if (!file) {
			return NULL;
		}

		string text;
		string line;
		unsigned short width, height;
		bool correcttype = false;
		vector<string> list;
		while (getline(file, line)) {
			text.append(line);
			text.append(" ");
			unsigned position = line.find("255");
			if (position != string::npos) {
				break;
			}
		}

		char* charText = stringToChar(text);
		list = split(charText, ' ');
		if (list[0] == "P3") {
			cerr << "P3 format is not supported." << endl;
			return NULL;
		}
		if (list[1] == "") {
			cerr << "The width of the image is not specified." << endl;
			return NULL;
		}
		width = mystoi(list[1]);
		if (list[2] == "") {
			cerr << "The height of the image is not specified." << endl;
			return NULL;
		}
		height = mystoi(list[2]);
		if (list[3] == "") {
			cerr << "The maximum value is not specified." << endl;
			return NULL;
		}
		if (mystoi(list[3]) > 255) {
			cerr << "Maximum value is over 255!" << endl;
			return NULL;
		}

		char* data = new char[width * height * 3];
		float* fdata = new float[width * height * 3];
		file.read(data, width * height * 3 * sizeof(char));

		for (int i = 0; i < width * height * 3; i++) {
			char t = data[i];
			unsigned char tt = (unsigned char)t;
			float pp = tt / 255.0f;
			fdata[i] = pp;
		}

		Image *image = new Image(width, height, (component_t*)fdata);
		delete[] data;
		return image;
	}
}