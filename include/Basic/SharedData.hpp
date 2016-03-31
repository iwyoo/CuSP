#pragma once

#include <cstring>

namespace cusp {

template <typename TElem = float, typename TInt = int>
class SharedData {
	public :
		SharedData(TElem *_cpuPtr, 
				TInt _elemNum, bool deepCopy=false);
		~SharedData();

		void synchToCPU();
		void synchToGPU();
		friend class SmartPointer;

	private:
		TElem *cpuPtr;
		TElem *gpuPtr;
		const TInt elemNum;
		const TInt dataSize;
		const bool deepCopy;
};

}

#include "basic/SharedData.tpp"
