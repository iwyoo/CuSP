#include "cuspCUDA.cuh"
#include "cuspCUDA.hpp"

namespace cusp {

template <typename TElem, typename TInt>
__global__ void matrix_element_add_kernel(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	if (blockIdx.x < nRow && threadIdx.x < nCol) {
		TInt i = blockDim.x * blockIdx.x + threadIdx.x;
		a[i] += b;
	}
}

template <typename TElem, typename TInt>
__global__ void matrix_element_sub_kernel(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	if (blockIdx.x < nRow && threadIdx.x < nCol) {
		TInt i = blockDim.x * blockIdx.x + threadIdx.x;
		a[i] -= b;
	}
}

template <typename TElem, typename TInt>
__global__ void matrix_element_mult_kernel(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	if (blockIdx.x < nRow && threadIdx.x < nCol) {
		TInt i = blockDim.x * blockIdx.x + threadIdx.x;
		a[i] *= b;
	}
}

template <typename TElem, typename TInt>
__global__ void matrix_element_div_kernel(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	if (blockIdx.x < nRow && threadIdx.x < nCol) {
		TInt i = blockDim.x * blockIdx.x + threadIdx.x;
		a[i] /= b;
	}
}

template <typename TElem, typename TInt>
__global__ void matrix_matrix_add_kernel(TElem *a, TElem *b, TInt nRow, TInt nCol)
{
	if (blockIdx.x < nRow && threadIdx.x < nCol) {
		TInt i = blockDim.x * blockIdx.x + threadIdx.x;
		a[i] += b[i];
	}
}

template <typename TElem, typename TInt>
__global__ void matrix_matrix_sub_kernel(TElem *a, TElem *b, TInt nRow, TInt nCol)
{
	if (blockIdx.x < nRow && threadIdx.x < nCol) {
		TInt i = blockDim.x * blockIdx.x + threadIdx.x;
		a[i] -= b[i];
	}
}

// future : optimization
template <typename TElem, typename TInt>
__global__ void matrix_matrix_mult_kernel(TElem *a, TElem *b, TElem *c, TInt nRow0, TInt nCol0, TInt nCol1)
{
	TInt col = blockDim.x*blockIdx.x + threadIdx.x;
	TInt row = blockDim.y*blockIdx.y + threadIdx.y;

	TElem sum=0;
	if (col < nCol1 && row < nRow0) {
		for (TInt k=0; k<nCol0; k++) {
			sum += a[row*nCol0+ k] * b[k*nCol1 + col];
		}
	}
	c[row*nCol1+col] = sum;
}

template <typename TElem, typename TInt>
void matrix_element_add(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	matrix_element_add_kernel<TElem, TInt> <<<nRow, nCol>>>(a, b, nRow, nCol);
}

template <typename TElem, typename TInt>
void matrix_element_sub(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	matrix_element_sub_kernel<TElem, TInt> <<<nRow, nCol>>>(a, b, nRow, nCol);
}

template <typename TElem, typename TInt>
void matrix_element_mult(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	matrix_element_mult_kernel<TElem, TInt> <<<nRow, nCol>>>(a, b, nRow, nCol);
}

template <typename TElem, typename TInt>
void matrix_element_div(TElem *a, TElem b, TInt nRow, TInt nCol)
{
	matrix_element_div_kernel<TElem, TInt> <<<nRow, nCol>>>(a, b, nRow, nCol);
}

template <typename TElem, typename TInt>
void matrix_matrix_add(TElem *a, TElem *b, TInt nRow, TInt nCol)
{
	matrix_matrix_add_kernel<TElem, TInt> <<<nRow, nCol>>>(a, b, nRow, nCol);
}

template <typename TElem, typename TInt>
void matrix_matrix_sub(TElem *a, TElem *b, TInt nRow, TInt nCol)
{
	matrix_matrix_sub_kernel<TElem, TInt> <<<nRow, nCol>>>(a, b, nRow, nCol);
}

// future : optimization
template <typename TElem, typename TInt>
void matrix_matrix_mult(TElem *a, TElem *b, TElem *c, TInt nRow0, TInt nCol0, TInt nCol1)
{
	dim3 dimGrid(1,1);
	dim3 dimBlock(nCol1,nRow0);
	matrix_matrix_mult_kernel<TElem, TInt> 
		<<<dimGrid, dimBlock>>> (a, b, c, nRow0, nCol0, nCol1);
}

}

#include "cuspCUDA.tpp"
