#include "cuspMatrix.hpp"
#include "cuspCUDA.hpp"
#include <iostream>

namespace cusp {

template <typename TElem, typename TInt>
Matrix<TElem, TInt>::
Matrix(TInt _row, TInt _col, TElem *_cpuPtr, TInt _elemNum, bool _autoSynch, bool _deepCopy)
: autoSynch(_autoSynch), gpuDirtyFlag(false), row(_row), col(_col),
  SmartPointer<TElem, TInt>(_cpuPtr, _elemNum, _deepCopy)
{
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> 
zeros(TInt row, TInt col, bool _autoSynch, TElem *_cpuPtr)
{
	if (row <= 0 && col <= 0) {
		std::cerr << " cusp error : " 
			<< " matrix row and column size must be larger than 0" 
			<< std::endl;
		exit(EXIT_FAILURE);
	} // future : error handling object

	TInt _elemNum = row*col;
	if (_cpuPtr == NULL) _cpuPtr = new TElem[_elemNum];
	for (int i=0; i<row*col; i++) _cpuPtr[i] = 0;
	return Matrix<TElem, TInt>(row, col, _cpuPtr, _elemNum, _autoSynch, true);
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> 
ones(TInt row, TInt col, bool _autoSynch, TElem *_cpuPtr)
{
	if (row <= 0 && col <= 0) {
		std::cerr << " cusp error : " 
			<< " matrix row and column size must be larger than 0" 
			<< std::endl;
		exit(EXIT_FAILURE);
	} // future : error handling object

	TInt _elemNum = row*col;
	if (_cpuPtr == NULL) _cpuPtr = new TElem[_elemNum];
	for (int i=0; i<row*col; i++) _cpuPtr[i] = 1;
	return Matrix<TElem, TInt>(row, col, _cpuPtr, _elemNum, _autoSynch, true);
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>&
Matrix<TElem, TInt>::operator+=(const TElem b)
{
	matrix_element_add( 
		this->getGpuPtr(), b, getRow(), getCol());

	gpuDirtyFlag = true; 
	if (autoSynch) this->synch();
}

template <typename TElem, typename TInt>
void Matrix<TElem, TInt>::print()
{
	if (autoSynch) this->synch();
	const TElem *cpuPtr = this->getCpuPtr();
	for (int i=0;i<row; i++) {
		for (int j=0;j<col; j++) {
			std::cout << cpuPtr[i*col + j] << " ";
		}
		std::cout << std::endl;
	}
}

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
