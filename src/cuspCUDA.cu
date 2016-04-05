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
__global__ void matrix_element_sub_kernel(TElem *a, TElem b, TInt row, TInt col)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (blockIdx.x < row && threadIdx.x < col)
		a[i] -= b;
}

template <typename TElem, typename TInt>
__global__ void matrix_element_mult_kernel(TElem *a, TElem b, TInt row, TInt col)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (blockIdx.x < row && threadIdx.x < col)
		a[i] *= b;
}

template <typename TElem, typename TInt>
__global__ void matrix_element_div_kernel(TElem *a, TElem b, TInt row, TInt col)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (blockIdx.x < row && threadIdx.x < col)
		a[i] /= b;
}

template <typename TElem, typename TInt>
__global__ void matrix_matrix_add_kernel(TElem *a, TElem *b, TInt row, TInt col)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (blockIdx.x < row && threadIdx.x < col)
		a[i] += b[i];
}

template <typename TElem, typename TInt>
__global__ void matrix_matrix_sub_kernel(TElem *a, TElem *b, TInt row, TInt col)
{
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (blockIdx.x < row && threadIdx.x < col)
		a[i] -= b[i];
}

template <typename TElem, typename TInt>
void matrix_element_add(TElem *a, TElem b, TInt row, TInt col)
{
	matrix_element_add_kernel<TElem, TInt> <<<row, col>>>(a, b, row, col);
}

template <typename TElem, typename TInt>
void matrix_element_sub(TElem *a, TElem b, TInt row, TInt col)
{
	matrix_element_sub_kernel<TElem, TInt> <<<row, col>>>(a, b, row, col);
}

template <typename TElem, typename TInt>
void matrix_element_mult(TElem *a, TElem b, TInt row, TInt col)
{
	matrix_element_mult_kernel<TElem, TInt> <<<row, col>>>(a, b, row, col);
}

template <typename TElem, typename TInt>
void matrix_element_div(TElem *a, TElem b, TInt row, TInt col)
{
	matrix_element_div_kernel<TElem, TInt> <<<row, col>>>(a, b, row, col);
}

template <typename TElem, typename TInt>
void matrix_matrix_add(TElem *a, TElem *b, TInt row, TInt col)
{
	matrix_matrix_add_kernel<TElem, TInt> <<<row, col>>>(a, b, row, col);
}

template <typename TElem, typename TInt>
void matrix_matrix_sub(TElem *a, TElem *b, TInt row, TInt col)
{
	matrix_matrix_sub_kernel<TElem, TInt> <<<row, col>>>(a, b, row, col);
}

}

#include "cuspCUDA.tpp"
