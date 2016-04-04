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
	for (int i=0; i<row*col; i++) _cpuPtr[i] = 0;
	return Matrix<TElem, TInt>(row, col, _cpuPtr, _elemNum, _autoSynch, true);
}

/*
template <typename TElem, typename TInt>
Matrix<TElem, TInt, 2> 
Matrix<TElem, TInt, 2>::zeros(TInt row, TInt col, 
	bool _autoSynch, TElem *_cpuPtr)
{
	if (row <= 0 && col <= 0) {
		std::cerr << " cusp error : " 
			<< " matrix row and column size must be larger than 0" 
			<< std::endl;
		exit(EXIT_FAILURE);
	} // future : error handling object
	TElem *_cpuPtr = new TElem[row*col];	
	for (int i=0; i<row*col; i++)
		_cpuPtr[i] = 1;
	return mat(row, col, _autoSynch, _cpuPtr);
}
*/

template <typename TElem, typename TInt>
Matrix<TElem, TInt>&
Matrix<TElem, TInt>::operator+=(const TElem b)
{
	matrix_element_add( 
		SmartPointer<TElem, TInt>::getGpuPtr(), b, getRow(), getCol());

	gpuDirtyFlag = true; 
	if (autoSynch) this->synch();
}

//template class Matrix<char, unsigned int>;
//template class Matrix<char, unsigned long long>;
//template class Matrix<short, unsigned int>;
//template class Matrix<short, unsigned long long>;
//template class Matrix<int, unsigned int>;
//template class Matrix<int, unsigned long long>;
template class Matrix<float, unsigned int>;
//template class Matrix<float, unsigned long long>;
//template class Matrix<double, unsigned int>;
//template class Matrix<double, unsigned long long>;

}
