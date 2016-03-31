#include "cuda.h"
#include "array/array.cuh"

namespace cusp {

template <typename TElem, typename TInt, unsigned int nDim>
array<TElem,TInt,nDim>::array(
	TElem *_cpuPtr, TInt _elemNum, Shape<TInt,nDim> _shape,
	bool _wrapped=false, bool _deepCopy=false)
: SmartPointer<TElem, TInt>(_cpuPtr, _elemNum, _deepCopy), 
	shape<TInt,nDim>(_shape),wrapped(wrapped)
{
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
