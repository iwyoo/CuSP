#pragma once

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int>
void matrix_element_add(TElem *a, TElem b, TInt row, TInt col);

}
