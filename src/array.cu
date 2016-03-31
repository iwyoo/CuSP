#include "array.cuh"

namespace cusp {

template <typename TElem, typename TInt>
__global__
void assignWithAdd(TElem *a, const TElem b)
{
	int i = threadIdx.x;
	a[i] += b;
}

}
