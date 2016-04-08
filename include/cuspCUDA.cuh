#pragma once

namespace cusp {

template <typename TElem, typename TInt>
__global__ void matrix_element_add_kernel(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
__global__ void matrix_element_sub_kernel(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
__global__ void matrix_element_mult_kernel(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
__global__ void matrix_element_div_kernel(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
__global__ void matrix_matrix_add_kernel(TElem *a, TElem *b, TInt row, TInt col);

template <typename TElem, typename TInt>
__global__ void matrix_matrix_sub_kernel(TElem *a, TElem *b, TInt row, TInt col);

template <typename TElem, typename TInt>
__global__ void matrix_matrix_mult_kernel(TElem *a, TElem *b, TElem *c, TInt nRow0, TInt nCol0, TInt nCol1);

}
