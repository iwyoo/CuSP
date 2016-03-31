#pragma once

namespace cusp {

template <typename TInt = unsigned int, unsigned int nDim = 1>
class Shape {
	public :
		TInt & operator[](unsigned int i)
			{ return dims[i]; }
		TInt operator[](unsigned int i) const
			{ return dims[i]; }
	private :
		TInt[nDim] dims; 
};

}
