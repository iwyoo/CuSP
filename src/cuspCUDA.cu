#include "cuspCUDA.cuh"
#include "cuspCUDA.hpp"

namespace cusp {

template <typename TElem, typename TInt>
__global__ void matrix_element_add_kernel(TElem *a, TElem b, TInt row, TInt col)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (blockIdx.x < row && threadIdx.x < col)
		a[i] += b;
}

template <typename TElem, typename TInt>
void matrix_element_add(TElem *a, TElem b, TInt row, TInt col)
{
	matrix_element_add_kernel<TElem, TInt> <<<row, col>>>(a, b, row, col);
}

template void matrix_element_add<float, unsigned int> 
	(float *a, float b, unsigned int row, unsigned  int col);
template void matrix_element_add<float, unsigned long long> 
	(float *a, float b, unsigned long long row, unsigned long long col);
template void matrix_element_add<double, unsigned int> 
	(double *a, double b, unsigned int row, unsigned  int col);
template void matrix_element_add<double, unsigned long long> 
	(double *a, double b, unsigned long long row, unsigned long long col);

}
