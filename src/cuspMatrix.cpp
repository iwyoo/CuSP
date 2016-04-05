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
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator+=(const TElem b)
{
	matrix_element_add( 
		this->getGpuPtr(), b, getRow(), getCol());

	gpuDirtyFlag = true; 
	if (autoSynch) this->synch();
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator-=(const TElem b)
{
	matrix_element_sub( 
		this->getGpuPtr(), b, getRow(), getCol());

	gpuDirtyFlag = true; 
	if (autoSynch) this->synch();
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator*=(const TElem b)
{
	matrix_element_mult( 
		this->getGpuPtr(), b, getRow(), getCol());

	gpuDirtyFlag = true; 
	if (autoSynch) this->synch();
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator/=(const TElem b)
{
	matrix_element_div( 
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

}

#include "cuspMatrix.tpp"
