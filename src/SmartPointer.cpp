#include "SmartPointer.hpp"
#include "SharedData.hpp"
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

template class SmartPointer<float, unsigned int>;
//template class SmartPointer<float, unsigned long long>;
//template class SmartPointer<double, unsigned int>;
//template class SmartPointer<double, unsigned long long>;

}
