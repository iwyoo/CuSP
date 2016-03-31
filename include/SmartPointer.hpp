#pragma once

#include <memory>
#include "SharedData.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int>
class SmartPointer {
	public:
		typedef SharedData<TElem, TInt> SharedDataType;
		typedef std::shared_ptr<SharedDataType> SharedDataPtrType;

		SmartPointer(const SmartPointer<TElem, TInt>& _sp); 
		SmartPointer(TElem *_cpuPtr, 
					 TInt _elemNum, bool deepCopy = false); 
		~SmartPointer();
	
	protected:
		TElem* const getGpuPtr() const { return sharedDataPtr->gpuPtr; }
		TInt getElemNum() const { return sharedDataPtr->elemNum; }
		TInt getDataSize() const { return sharedDataPtr->dataSize; }

	private:
		 SharedDataPtrType sharedDataPtr;

};

}

#include "SmartPointer.tpp"
