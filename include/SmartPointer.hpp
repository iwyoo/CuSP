#pragma once

#include <memory>
#include "SharedData.hpp"

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

	protected :
		ElemType* getGpuPtr() const 
			{ return sharedDataPtr->getGpuPtr(); }
		SizeType getElemNum() const 
			{ return sharedDataPtr->GetElemNum(); }
		SizeType getDataSize() const 
			{ return sharedDataPtr->GetDataSize(); }

	private:
		 SharedDataPtrType sharedDataPtr;

};

}

#include "SmartPointer.tpp"
