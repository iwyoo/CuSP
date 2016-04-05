#include "cuspSharedData.hpp" 
#include <cuda_runtime_api.h>
#include <cuda.h>

namespace cusp {

template <typename TElem, typename TInt>
SharedData<TElem,TInt>::
SharedData(TElem *_cpuPtr, TInt _elemNum, bool _deepCopy)
: elemNum(_elemNum), dataSize(_elemNum*sizeof(TElem)), 
  cpuPtr(_cpuPtr), deepCopy(_deepCopy)
{
	if (deepCopy) {
		cpuPtr = new TElem[elemNum];
		std::memcpy(cpuPtr, _cpuPtr, dataSize);
	} else cpuPtr = _cpuPtr;

	cudaMalloc( (void**)&gpuPtr, dataSize);
	cudaMemcpy( gpuPtr, cpuPtr, dataSize, cudaMemcpyHostToDevice );
}

template <typename TElem, typename TInt>
SharedData<TElem,TInt>::~SharedData()
{
	cudaFree(gpuPtr);
}

template <typename TElem, typename TInt>
void 
SharedData<TElem,TInt>::synchToCPU()
{
	cudaMemcpy( cpuPtr, gpuPtr, dataSize, cudaMemcpyDeviceToHost );
}

template <typename TElem, typename TInt>
void 
SharedData<TElem,TInt>::synchToGPU()
{
	cudaMemcpy( gpuPtr, cpuPtr, dataSize, cudaMemcpyHostToDevice );
}

}

#include "cuspSharedData.tpp"
