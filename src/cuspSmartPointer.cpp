#include "cuspSmartPointer.hpp"
#include "cuspSharedData.hpp"
#include <memory>

namespace cusp {

template <typename TElem, typename TInt>
SmartPointer<TElem,TInt>::
SmartPointer(TElem *_cpuPtr, TInt _elemNum)
{
	typedef SharedData<TElem, TInt> SharedDataType;
	typedef std::shared_ptr<SharedDataType> SharedDataPtrType;
	sharedDataPtr = SharedDataPtrType(
		new SharedData<TElem,TInt>(_cpuPtr, _elemNum));
}

template <typename TElem, typename TInt>
void SmartPointer<TElem, TInt>::flagGPU()
{
	if (cpuDirtyFlag) {
		this->synchToGPU();
		cpuDirtyFlag = false;
	}
	gpuDirtyFlag = true;
}

template <typename TElem, typename TInt>
void SmartPointer<TElem, TInt>::flagCPU()
{
	if (gpuDirtyFlag) {
		this->synchToCPU();
		gpuDirtyFlag = false;
	}
	cpuDirtyFlag = true;
}

}

#include "cuspSmartPointer.tpp"
