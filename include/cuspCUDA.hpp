#pragma once

namespace cusp {

template <typename TElem, typename TInt>
void matrix_element_add(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
void matrix_element_sub(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
void matrix_element_mult(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
void matrix_element_div(TElem *a, TElem b, TInt row, TInt col);

template <typename TElem, typename TInt>
void matrix_matrix_add(TElem *a, TElem *b, TInt row, TInt col);

template <typename TElem, typename TInt>
void matrix_matrix_sub(TElem *a, TElem *b, TInt row, TInt col);

template <typename TElem, typename TInt>
void matrix_matrix_mult(TElem *a, TElem *b, TElem *c, TInt nRow0, TInt nCol0, TInt nCol1);
}
