

#include "ppm_format.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
using namespace imaging;

int mystoi(string data) {
	return atoi(data.c_str());
}

namespace imaging {
	vector<string> split(const char *str, char c = ' ') {
		vector<string> result;
		do {
			const char *begin = str;
			while (*str != c && *str)
				str++;
			result.push_back(string(begin, str));
		} while (0 != *str++);
		return result;
	}
	char* stringToChar(string &str) {
		char * charstr = new char[str.length() + 1];
		strcpy(charstr, str.c_str());
		return charstr;
	}
	Image* ReadPPM(const char* filename) {
		ifstream file(filename, ios_base::binary);
		if (!file) {
			cerr << "The file does not exist!" << endl;
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
			cerr << "P3 format is not supported" << endl;
			return NULL;
		}
		if (list[1] == "") {
			cerr << "The width of the image is not specified!" << endl;
			return NULL;
		}
		width = mystoi(list[1]);
		if (list[2] == "") {
			cerr << "The height of the image is not specified!" << endl;
			return NULL;
		}
		height = mystoi(list[2]);
		if (list[3] == "") {
			cerr << "The maximum value is not specified!" << endl;
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
			float p = tt / 255.0f;
			fdata[i] = p;
		}
		Image *img = new Image(width, height, (float*)fdata);
		delete[] data;
		return img;
	}
	bool WritePPM(Image& src, const char* filename) {
		ofstream file(filename, ios_base::binary);
		string typeOfPPM = "P6";
		char space = '\n';
		unsigned short width = src.getWidth();
		unsigned short height = src.getHeight();
		unsigned short value = 255;
		file << typeOfPPM;
		file << space;
		file << width;
		file << space;
		file << height;
		file << space;
		file << value;
		file << space;

		float* data = (float*)src.getRawDataPtr();
		for (int i = 0; i < width * height * 3; i++) {
			float pp = data[i] * 255.0f;
			unsigned char aa = (unsigned char)pp;
			file << aa;
		}
		file.flush();
		file.close();
		return true;
	}
}

