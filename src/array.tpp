#include "cuda.h"
#include "array.cuh"

namespace cusp {

template <typename TElem, typename TInt>
void array::operator+=(const TElem value)
{
	ElemType const *gpuPtr = getGpuPtr();
	assignWithAdd<<< 1, getElemNum() >>>(gpuPtr, value);
	cudaDeviceSynchronize();
}

}
