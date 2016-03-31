#pragma once

#include "SmartPointer.hpp"
#include "Shape.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int, unsigned int nDim = 1>
class array : public SmartPointer<TElem, TInt> {
	public :
		// To Do List
		// constructor
		// generater wrapper (ones rand)
		// operator overloading
		// reshape method

		array(TElem *_cpuPtr, TInt _elemNum, Shape<TInt,nDims> _shape,
			bool wrapped=false, bool deepCopy=false);
	
		void operator+=(const ElemType value);
		
		template <typename ...Dims>
		friend array zeros(Dims... dims);

		~array();

	private :
		const Shape<TInt,nDim> shape;
		const bool wrapped;
};

}

#include "array.tpp"
