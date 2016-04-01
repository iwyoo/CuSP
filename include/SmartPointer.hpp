#pragma once

#include <memory>
#include "SharedData.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int>
class SmartPointer {
	public:
		typedef SharedData<TElem, TInt> SharedDataType;
		typedef std::shared_ptr<SharedDataType> SharedDataPtrType;

		SmartPointer(TElem *_cpuPtr, TInt _elemNum, bool deepCopy=false); 

	protected:

		TElem* const getCpuPtr() const 
			{ return sharedDataPtr->getCpuPtr(); }
		TElem* const getGpuPtr() const 
			{ return sharedDataPtr->getGpuPtr(); }
		TInt getElemNum() const 
			{ return sharedDataPtr->getElemNum(); }
		TInt getDataSize() const 
			{ return sharedDataPtr->getDataSize(); }
	
	private:
		 SharedDataPtrType sharedDataPtr;

};

}
