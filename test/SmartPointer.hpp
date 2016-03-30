
#pragma once

#include "SharedData.hpp"
#include <memory>

namespace cusp {

template <typename TElem = float, typename TInt = int>
class SmartPointer {
	public:
		typedef TElem ElemType;
		typedef TInt  IntegerType;
		typedef SharedData<ElemType, IntegerType> SharedDataType;
		typedef std::shared_ptr<SharedDataType> SharedDataPtrType;

		SmartPointer(const SmartPointer<TElem, TInt>& _sp); 
		SmartPointer(ElemType *_cpuPtr, 
					IntegerType _elemNum, bool deepCopy = false); 
		~SmartPointer();
	private:
		 SharedDataPtrType sharedDataPtr;
};

}

#include "SmartPointer.tpp"
