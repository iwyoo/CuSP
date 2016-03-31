#pragma once

#include "SmartPointer.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int, unsigned int nDim = 1>
class array : public SmartPointer<TElem, TInt> {
	public :
		void operator+=(const ElemType value); // to test
		
		friend array<TElem, TInt, nDIm> ones(TInt n,...);
		friend array<TElem, TInt, nDIm> zeros(TInt n,...);
		friend array<TElem, TInt, nDIm> rand(TInt n,...);

	private :
		Dim dim[nDim];
};

}

#include "array.tpp"
