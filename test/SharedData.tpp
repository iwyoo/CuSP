namespace cusp {

template <typename TElem, typename TInt>
SharedData<TElem,TInt>::
SharedData(ElemType *_cpuPtr, IntegerType _elemNum, bool _deepCopy)
: elemNum(_elemNum), dataSize(_elemNum*sizeof(ElemType)), 
  cpuPtr(_cpuPtr), deepCopy(_deepCopy)
{
	if (deepCopy) {
		cpuPtr = new ElemType[elemNum];
		std::memcpy(cpuPtr, _cpuPtr, dataSize);
	} else cpuPtr = _cpuPtr;

	cudaMalloc( (void**)&gpuPtr, dataSize);
	cudaMemcpy( gpuPtr, cpuPtr, dataSize, cudaMemcpyHostToDevice );
}

template <typename TElem, typename TInt>
SharedData<TElem,TInt>::~SharedData()
{
	cudaFree(gpuPtr);
	return;
}

template <typename TElem, typename TInt>
void 
SharedData<TElem,TInt>::synchToCPU()
{
	cudaMemcpy( cpuPtr, gpuPtr, dataSize, cudaMemcpyDeviceToHost );
	return;
}

template <typename TElem, typename TInt>
void 
SharedData<TElem,TInt>::synchToGPU()
{
	cudaMemcpy( gpuPtr, cpuPtr, dataSize, cudaMemcpyHostToDevice );
	return;
}

}
