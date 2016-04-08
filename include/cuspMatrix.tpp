#include "cuspMatrix.hpp"

namespace cusp {

template class Matrix<float, int>;

template Matrix<float, int> ones (int row, int col, float *_cpuPtr);
template Matrix<float, int> zeros (int row, int col, float *_cpuPtr);

}
