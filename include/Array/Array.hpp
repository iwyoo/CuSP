#pragma once

#include "Basic/SmartPointer.hpp"
#include "Array/Shape.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int, unsigned int nDim = 1>
class array : public SmartPointer<TElem, TInt> {
	public :
		// To Do List
		// generater wrapper (ones rand)
		// operator overloading
		// reshape method

		array(TElem *_cpuPtr, TInt _elemNum, Shape<TInt,nDims> _shape,
			bool wrapped=false, bool deepCopy=false);
	
		template <typename ...Dims>
		friend array zeros(Dims... dims);

		void operator+=(const ElemType value);

		~array();

	private :
		const Shape<TInt,nDim> shape;
		const bool wrapped;
};

}

#include "Array/Array.tpp"
