#pragma once

#include <memory>
#include "cuspSharedData.hpp"

namespace cusp {

template <typename TElem, typename TInt>
class SmartPointer {
	public:
		typedef SharedData<TElem, TInt> SharedDataType;
		typedef std::shared_ptr<SharedDataType> SharedDataPtrType;

		SmartPointer(TElem *_cpuPtr, TElem *_gpuPtr, TInt _elemNum); 

		TElem* const getCpuPtr() const 
			{ return sharedDataPtr->getCpuPtr(); }
		TElem* const getGpuPtr() const 
			{ return sharedDataPtr->getGpuPtr(); }
		TInt getElemNum() const 
			{ return sharedDataPtr->getElemNum(); }
		TInt getDataSize() const 
			{ return sharedDataPtr->getDataSize(); }
		void flagGPU();
		void flagCPU();
		void flagOFF();
		void synch();
	
	protected:
		void synchToCPU()
			{ sharedDataPtr->synchToCPU(); }
		void synchToGPU()
			{ sharedDataPtr->synchToGPU(); }
	private:
		SharedDataPtrType sharedDataPtr;
		bool gpuDirtyFlag;
		bool cpuDirtyFlag;
};

}
