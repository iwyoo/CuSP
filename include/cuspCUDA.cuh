#pragma once

namespace cusp {

template <typename TElem, typename TInt>
__global__ void matrix_element_add_kernel(TElem *a, TElem b, TInt size);

template <typename TElem, typename TInt>
__global__ void matrix_element_sub_kernel(TElem *a, TElem b, TInt size);

template <typename TElem, typename TInt>
__global__ void matrix_element_mult_kernel(TElem *a, TElem b, TInt size);

template <typename TElem, typename TInt>
__global__ void matrix_element_div_kernel(TElem *a, TElem b, TInt size);

}
