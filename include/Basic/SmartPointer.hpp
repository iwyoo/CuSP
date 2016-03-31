#pragma once

#include <memory>
#include "basic/SharedData.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int>
class SmartPointer {
	public:
		typedef SharedData<TElem, TInt> SharedDataType;
		typedef std::shared_ptr<SharedDataType> SharedDataPtrType;

		SmartPointer(TElem *_cpuPtr, TInt _elemNum, bool deepCopy=false); 
	
	protected:
		TElem* const getCpuPtr() const { return sharedDataPtr->cpuPtr; }
		TElem* const getGpuPtr() const { return sharedDataPtr->gpuPtr; }
		TInt getElemNum() const { return sharedDataPtr->elemNum; }
		TInt getDataSize() const { return sharedDataPtr->dataSize; }

	private:
		 SharedDataPtrType sharedDataPtr;

};

}

#include "basic/SmartPointer.tpp"
