
#pragma once

#include "SharedData.hpp"
#include <memory>

namespace cusp {

template <typename TElem = float, typename TInt = int>
class SmartPointer {
	public:
		typedef TElem ElemType;
		typedef TInt  SizeType;
		typedef SharedData<ElemType, SizeType> SharedDataType;
		typedef std::shared_ptr<SharedDataType> SharedDataPtrType;

		SmartPointer(const SmartPointer<TElem, TInt>& _sp); 
		SmartPointer(ElemType *_cpuPtr, 
					 SizeType _elemNum, bool deepCopy = false); 
		~SmartPointer();
	private:
		 SharedDataPtrType sharedDataPtr;
};

}

#include "SmartPointer.tpp"
