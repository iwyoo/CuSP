#include "cuspCUDA.hpp"

namespace cusp {


template void matrix_element_add<float, int> 
	(float *a, float b, int row, int col);

template void matrix_element_sub<float, int> 
	(float *a, float b, int row, int col);

template void matrix_element_mult<float, int> 
	(float *a, float b, int row, int col);

template void matrix_element_div<float, int> 
	(float *a, float b, int row, int col);

template void matrix_matrix_add<float, int> 
	(float *a, float *b, int row, int col);

template void matrix_matrix_sub<float, int> 
	(float *a, float *b, int row, int col);
}
