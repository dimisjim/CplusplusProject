//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2016
//
//

#ifndef _ARRAY_IMPLEMENTATION_
#define _ARRAY_IMPLEMENTATION_

namespace math
{

	//--------------------------------------------------------------------------------------------
	// This file is included from the templated Array class header.
	// TODO: Provide its member function implementations here:
	//--------------------------------------------------------------------------------------------
	template <typename T>
	void * const Array<T>::getRawDataPtr() {
		return buffer;
	}
	template <typename T>
	T & Array<T>::operator () (int x, int y) {
		return buffer[y*getWidth() + x];
	}
	template <typename T>
	const T & Array<T>::operator () (int x, int y) const {
		return buffer[y*getWidth() + x];
	}
	template <typename T>
	Array<T>::Array(unsigned int w, unsigned int h) {
		(*this).width = w;
		(*this).height = h;
		(*this).buffer = new T[width*height];
	}
	template <typename T>
	Array<T>::Array(const Array<T> & src) {
		(*this).width = src.getWidth();
		(*this).height = src.getHeight();
		(*this).buffer = new T[width*height];
		(*this).buffer = src.buffer;
	}
	template <typename T>
	Array<T> & Array<T>::operator = (const Array<T> & source) {
		return *this;
	}
	template <typename T>
	bool Array<T>::operator == (const Array<T> & source) const {
		return true;
	}
	template <typename T>
	Array<T>::~Array() {
		delete[] buffer;
	}
} // namespace math

#endif