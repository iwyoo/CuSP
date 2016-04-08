#pragma once

#include <cstring>

namespace cusp {

template <typename TElem, typename TInt>
class SharedData {
	public :
		SharedData(TElem *_cpuPtr, TElem *_gpuPtr, TInt _elemNum);
		~SharedData();

		void synchToCPU();
		void synchToGPU();
		TElem* const getCpuPtr() const { return cpuPtr; }
		TElem* const getGpuPtr() const { return gpuPtr; }
		TInt getElemNum() const { return elemNum; }
		TInt getDataSize() const { return dataSize; }

	private:
		TElem *cpuPtr;
		TElem *gpuPtr;
		const TInt elemNum;
		const TInt dataSize;
};

}
