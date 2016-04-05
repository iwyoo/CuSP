#include "cuspSharedData.hpp" 
#include <cuda_runtime_api.h>
#include <cuda.h>

namespace cusp {

template <typename TElem, typename TInt>
SharedData<TElem,TInt>::
SharedData(TElem *_cpuPtr, TInt _elemNum)
: elemNum(_elemNum), dataSize(_elemNum*sizeof(TElem)), cpuPtr(_cpuPtr)
{
	cudaMalloc( (void**)&gpuPtr, dataSize);
	cudaMemcpy( gpuPtr, cpuPtr, dataSize, cudaMemcpyHostToDevice );
}

template <typename TElem, typename TInt>
SharedData<TElem,TInt>::~SharedData()
{
	cudaFree(gpuPtr);
	delete [] cpuPtr;
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
