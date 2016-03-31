
#include "SmartPointer.hpp"

namespace cusp {

template <typename TElem, typename TInt>
void array<TElem, TInt>::operator+=(const TElem value)
{
	ElemType const *gpuPtr = this->sharedDataPtr->getGpuPtr();

	// gpu operation

}

}
