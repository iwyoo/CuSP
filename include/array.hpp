#pragma once

#include "SmartPointer.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = int>
class array : public SmartPointer<TElem, TInt> {
	public :
		typedef TElem ElemType;
		typedef TInt  SizeType;

		void operator+=(const TElem value); // to test

		// friends function
		// ones
		// zeros
		// rand

	private :
		// dimension info?

};

}

#include "array.tpp"
