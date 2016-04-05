#include "cuspMatrix.hpp"

namespace cusp {

template class Matrix<char, int>;
template class Matrix<char, unsigned int>;
template class Matrix<char, unsigned long long>;
template class Matrix<short, int>;
template class Matrix<short, unsigned int>;
template class Matrix<short, unsigned long long>;
template class Matrix<int, int>;
template class Matrix<int, unsigned int>;
template class Matrix<int, unsigned long long>;
template class Matrix<float, int>;
template class Matrix<float, unsigned int>;
template class Matrix<float, unsigned long long>;
template class Matrix<double, int>;
template class Matrix<double, unsigned int>;
template class Matrix<double, unsigned long long>;

template Matrix<char, int> ones
(int row, int col, bool _autoSynch, char *_cpuPtr);
template Matrix<char, unsigned int> ones
(unsigned int row, unsigned int col, bool _autoSynch, char *_cpuPtr);
template Matrix<char, unsigned long long> ones
(unsigned long long row, unsigned long long col, bool _autoSynch, char *_cpuPtr);
template Matrix<short, int> ones
(int row, int col, bool _autoSynch, short *_cpuPtr);
template Matrix<short, unsigned int> ones
(unsigned int row, unsigned int col, bool _autoSynch, short *_cpuPtr);
template Matrix<short, unsigned long long> ones
(unsigned long long row, unsigned long long col, bool _autoSynch, short *_cpuPtr);
template Matrix<int, int> ones
(int row, int col, bool _autoSynch, int *_cpuPtr);
template Matrix<int, unsigned int> ones
(unsigned int row, unsigned int col, bool _autoSynch, int *_cpuPtr);
template Matrix<int, unsigned long long> ones
(unsigned long long row, unsigned long long col, bool _autoSynch, int *_cpuPtr);
template Matrix<float, int> ones
(int row, int col, bool _autoSynch, float *_cpuPtr);
template Matrix<float, unsigned int> ones
(unsigned int row, unsigned int col, bool _autoSynch, float *_cpuPtr);
template Matrix<float, unsigned long long> ones
(unsigned long long row, unsigned long long col, bool _autoSynch, float *_cpuPtr);
template Matrix<double, int> ones
(int row, int col, bool _autoSynch, double *_cpuPtr);
template Matrix<double, unsigned int> ones
(unsigned int row, unsigned int col, bool _autoSynch, double *_cpuPtr);
template Matrix<double, unsigned long long> ones
(unsigned long long row, unsigned long long col, bool _autoSynch, double *_cpuPtr);

template Matrix<char, int> zeros
(int row, int col, bool _autoSynch, char *_cpuPtr);
template Matrix<char, unsigned int> zeros
(unsigned int row, unsigned int col, bool _autoSynch, char *_cpuPtr);
template Matrix<char, unsigned long long> zeros
(unsigned long long row, unsigned long long col, bool _autoSynch, char *_cpuPtr);
template Matrix<short, int> zeros
(int row, int col, bool _autoSynch, short *_cpuPtr);
template Matrix<short, unsigned int> zeros
(unsigned int row, unsigned int col, bool _autoSynch, short *_cpuPtr);
template Matrix<short, unsigned long long> zeros
(unsigned long long row, unsigned long long col, bool _autoSynch, short *_cpuPtr);
template Matrix<int, int> zeros
(int row, int col, bool _autoSynch, int *_cpuPtr);
template Matrix<int, unsigned int> zeros
(unsigned int row, unsigned int col, bool _autoSynch, int *_cpuPtr);
template Matrix<int, unsigned long long> zeros
(unsigned long long row, unsigned long long col, bool _autoSynch, int *_cpuPtr);
template Matrix<float, int> zeros
(int row, int col, bool _autoSynch, float *_cpuPtr);
template Matrix<float, unsigned int> zeros
(unsigned int row, unsigned int col, bool _autoSynch, float *_cpuPtr);
template Matrix<float, unsigned long long> zeros
(unsigned long long row, unsigned long long col, bool _autoSynch, float *_cpuPtr);
template Matrix<double, int> zeros
(int row, int col, bool _autoSynch, double *_cpuPtr);
template Matrix<double, unsigned int> zeros
(unsigned int row, unsigned int col, bool _autoSynch, double *_cpuPtr);
template Matrix<double, unsigned long long> zeros
(unsigned long long row, unsigned long long col, bool _autoSynch, double *_cpuPtr);

}
