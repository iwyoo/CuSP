#pragma once

namespace cusp {

template < typename TInt = unsigned int, unsigned int nDim = 1 >
class Dim {
	public :
		TInt & operator[] (Tint i) 
		{ return dimSize[i]; }
		TInt operator[] (Tint i) const
		{ return dimSize[i]; }

		Dim(TInt n, ...);

	private :
		TInt dimSize[nDim];
};

}

#include "Dim.tpp"
