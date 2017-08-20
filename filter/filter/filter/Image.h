//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2015 - 2016
//
//

#ifndef _IMAGE
#define _IMAGE

#include "Vec3.h"
#include "Array.h"
#include "Serializable.h"

using namespace math;

/*! The imaging namespace contains every class or function associated with the image storage, compression and manipulation.
*/
namespace imaging
{

	//------------------------------------ class Image ------------------------------------------------

	/*! It is the class that represents a generic data container for an image.
	*
	* It holds the actual buffer of the pixel values and provides methods for accessing them,
	* either as individual pixels or as a memory block. The Image class alone does not provide
	* any functionality for loading and storing an image, as it is the result or input to such a procedure.
	*
	* The internal buffer of an image object stores the actual bytes (data) of the color image as
	* a contiguous sequence of RGB triplets. Hence, the size of the buffer variable holding these data is
	* 3 X width X height X sizeof(component_t) bytes.
	*
	* All values stored in the internal memory buffer are floating point values and for typical (normalized)
	* intensity ranges, each color component is within the range [0.0, 1.0].
	*
	* \see component_t
	*/
	class Image : public Serializable, public Array<Vec3<float>>
	{
	public:
		enum channel_t { RED = 0, GREEN, BLUE };          //! You can use the names RED, GREEN, BLUE instead of 0,1,2 to access individual Color channels.

	public:
		Vec3<float> getPixel(unsigned int x, unsigned int y) const;    // get the color of the image at location (x,y)
																 // Do any necessary bound checking. Also take into account
																 // the "interleaved" flag to fetch the appropriate data
																 // Return a black (0,0,0) color in case of an out-of-bounds
																 // x,y pair

																 // data mutators
		void setPixel(unsigned int x, unsigned int y, Vec3<float> & value);
		// Set the RGB values for an (x,y) pixel. Do all 
		// necessary bound checks and respect the "interleaved"
		// flag when updating our data.

		void setData(const float * & data_ptr);            // Copy the data from data_ptr to the internal buffer.
																 // The function ASSUMES a proper size for the incomming data array.

																 // constructors and destructor										     // default: zero dimensions, nullptr for the buffer.	
		Image(unsigned int width, unsigned int height);
		Image(unsigned int width, unsigned int height, const float * data_ptr);

		virtual bool operator << (std::string filename);     
		virtual bool operator >> (std::string filename);

	};

} //namespace imaging

#endif