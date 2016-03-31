#pragma once

#include <cstring>
#include "cuda.h"

namespace cusp {

template <typename TElem = float, typename TInt = int>
class SharedData {
	public :
		typedef TElem ElemType;
		typedef TInt  SizeType;

		SharedData(ElemType *_cpuPtr, 
				SizeType _elemNum, bool deepCopy=false);
		~SharedData();

		void synchToCPU();
		void synchToGPU();
		ElemType* getGpuPtr() const { return gpuPtr; }
		SizeType getElemNum() const { return elemNum; }
		SizeType getDataSize() const { return dataSize; }

	private:
		ElemType *cpuPtr;
		ElemType *gpuPtr;
		const SizeType elemNum;
		const SizeType dataSize;
		const bool deepCopy;
};

}

#include "SharedData.tpp"
