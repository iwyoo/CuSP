#include "cuda.h"
#include "array.cuh"
#include <cassert>

namespace cusp {

template <typename TElem, typename TInt, unsigned int nDim>
array<TElem,TInt,nDim>::array(
	TElem *_cpuPtr, TInt _elemNum, Shape<TInt,nDim> _shape,
	bool _wrapped=false, bool _deepCopy=false)
: SmartPointer<TElem, TInt>(_cpuPtr, _elemNum, _deepCopy), 
	shape<TInt,nDim>(_shape),wrapped(wrapped)
{
}


template <typename TElem, typename TInt, unsigned int nDim, typename ...Dims>
array<TElem,TInt,nDim>::array zeros(Dims... _dims)
{
	static_assert(std::is_all_same<TInt, Dims...>::value, 
		"Type doesn't match. Each dimension value type must be TInt.");
	TInt dims[nDim] = {_dims...};
	TInt elemNum = 1;
	Shape<TInt,nDim> shape;
	for (int i=0; i<nDim; i++) { 
		assert(dims[i] > 0);
		shape[i] = dims[i];
		elemNum *= dims[i];
	}

	TElem *cpuPtr = new TElem[elemNum];
	for (int i=0; i<elemNum; i++) cpuPtr[i] = 0;
	return array(cpuPtr, elemNum, shape, true);
}

template <typename TElem, typename TInt, unsigned int nDim>
array<TElem,TInt,nDim>::~array()
{
	if (wrapped) delete [] getCpuPtr();
}

template <typename TElem, typename TInt, unsigned int nDim>
void array<TElem,TInt,nDim>::operator+=(const TElem value)
{
	ElemType const *gpuPtr = getGpuPtr();
	assignWithAdd<<< 1, getElemNum() >>>(gpuPtr, value);
	cudaDeviceSynchronize();
}

}
