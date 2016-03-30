#pragma once

#include <cstring>
#include "cuda.h"

namespace cusp {

template <typename TElem = float, typename TInt = int>
class SharedData {
	public :
		typedef TElem ElemType;
		typedef TInt  IntegerType;

		SharedData(ElemType *_cpuPtr, 
				IntegerType _elemNum, bool deepCopy=false);
		~SharedData();

		void synchToCPU();
		void synchToGPU();

	private:
		ElemType *cpuPtr;
		ElemType *gpuPtr;
		const IntegerType elemNum;
		const IntegerType dataSize;
		const bool deepCopy;
};

}

#include "SharedData.tpp"
