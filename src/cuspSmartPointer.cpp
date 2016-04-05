#include "cuspSmartPointer.hpp"
#include "cuspSharedData.hpp"
#include <memory>

namespace cusp {

template <typename TElem, typename TInt>
SmartPointer<TElem,TInt>::
SmartPointer(TElem *_cpuPtr, TInt _elemNum, bool deepCopy)
{
	typedef SharedData<TElem, TInt> SharedDataType;
	typedef std::shared_ptr<SharedDataType> SharedDataPtrType;
	sharedDataPtr = SharedDataPtrType(
		new SharedData<TElem,TInt>(_cpuPtr, _elemNum, deepCopy));
}

}

#include "cuspSmartPointer.tpp"
