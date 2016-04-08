#include "cuspMatrix.hpp"
#include "cuspCUDA.hpp"
#include <iostream>
#include <cstring>

namespace cusp {

template <typename TElem, typename TInt>
Matrix<TElem, TInt>::
Matrix(TInt _nRow, TInt _nCol, TElem *_cpuPtr, TElem *_gpuPtr)
: nRow(_nRow), nCol(_nCol),
 SmartPointer<TElem, TInt>(_cpuPtr, _gpuPtr, _nRow*_nCol)
{
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> 
zeros(TInt nRow, TInt nCol, TElem *_cpuPtr)
{
	if (nRow <= 0 || nCol <= 0) {
		std::cerr << " cusp error : " 
			<< " matrix row and column size must be larger than 0" 
			<< std::endl;
		exit(EXIT_FAILURE);
	} // future : error handling 

	TInt _elemNum = nRow*nCol;
	if (_cpuPtr == NULL) _cpuPtr = new TElem[_elemNum];
	for (int i=0; i<nRow*nCol; i++) _cpuPtr[i] = 0;
	return Matrix<TElem, TInt>(nRow, nCol, _cpuPtr, NULL);
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> 
ones(TInt nRow, TInt nCol, TElem *_cpuPtr)
{
	if (nRow <= 0 || nCol <= 0) {
		std::cerr << " cusp error : " 
			<< " matrix row and column size must be larger than 0" 
			<< std::endl;
		exit(EXIT_FAILURE);
	} // future : error handling

	TInt _elemNum = nRow*nCol;
	if (_cpuPtr == NULL) _cpuPtr = new TElem[_elemNum];
	for (int i=0; i<nRow*nCol; i++) _cpuPtr[i] = 1;
	return Matrix<TElem, TInt>(nRow, nCol, _cpuPtr, NULL);
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>
Matrix<TElem, TInt>::copy()
{
	this->synch();

	TElem *_cpuPtr = new TElem[this->getElemNum()];
	memcpy(_cpuPtr, this->getCpuPtr(), this->getDataSize());
	return Matrix<TElem, TInt>(nRow, nCol, _cpuPtr, this->getGpuPtr());
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator+=(const TElem b)
{
	this->flagGPU();
	matrix_element_add( 
		this->getGpuPtr(), b, getRow(), getCol());
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator-=(const TElem b)
{
	this->flagGPU();
	matrix_element_sub( 
		this->getGpuPtr(), b, getRow(), getCol());
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator*=(const TElem b)
{
	this->flagGPU();
	matrix_element_mult( 
		this->getGpuPtr(), b, getRow(), getCol());
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator/=(const TElem b)
{
	this->flagGPU();
	matrix_element_div( 
		this->getGpuPtr(), b, getRow(), getCol());
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> Matrix<TElem, TInt>::operator+(const TElem b)
{
	Matrix<TElem, TInt> tmpMat = this->copy();
	tmpMat.flagGPU();

	// future : error handling

	matrix_element_add(
		tmpMat.getGpuPtr(), b, getRow(), getCol());
	return tmpMat;
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> Matrix<TElem, TInt>::operator-(const TElem b)
{
	Matrix<TElem, TInt> tmpMat = this->copy();
	tmpMat.flagGPU();

	// future : error handling

	matrix_element_sub(
		tmpMat.getGpuPtr(), b, getRow(), getCol());
	return tmpMat;
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> Matrix<TElem, TInt>::operator*(const TElem b)
{
	Matrix<TElem, TInt> tmpMat = this->copy();
	tmpMat.flagGPU();

	// future : error handling

	matrix_element_mult(
		tmpMat.getGpuPtr(), b, getRow(), getCol());
	return tmpMat;
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> Matrix<TElem, TInt>::operator/(const TElem b)
{
	Matrix<TElem, TInt> tmpMat = this->copy();
	tmpMat.flagGPU();

	// future : error handling

	matrix_element_div(
		tmpMat.getGpuPtr(), b, getRow(), getCol());
	return tmpMat;
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator+=(Matrix& B)
{
	this->flagGPU();
	B.synch();

	// future : error handling

	matrix_matrix_add( 
		this->getGpuPtr(), B.getGpuPtr(), getRow(), getCol());
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator-=(Matrix& B)
{
	this->flagGPU();
	B.synch();

	// future : error handling

	matrix_matrix_sub( 
		this->getGpuPtr(), B.getGpuPtr(), getRow(), getCol());
}

/*
template <typename TElem, typename TInt>
Matrix<TElem, TInt>& Matrix<TElem, TInt>::operator*=(Matrix& B)
{
	this->flagGPU();
	B.synch();

	// future : error handling

	matrix_matrix_mult( 
		this->getGpuPtr(), B.getGpuPtr(), getRow(), getCol());
}
*/

template <typename TElem, typename TInt>
Matrix<TElem, TInt> Matrix<TElem, TInt>::operator+(Matrix& B)
{
	Matrix<TElem, TInt> tmpMat = this->copy();
	B.synch();
	tmpMat.flagGPU();

	// future : error handling

	matrix_matrix_add( 
		tmpMat.getGpuPtr(), B.getGpuPtr(), getRow(), getCol());

	return tmpMat;
}

template <typename TElem, typename TInt>
Matrix<TElem, TInt> Matrix<TElem, TInt>::operator-(Matrix& B)
{
	Matrix<TElem, TInt> tmpMat = this->copy();
	B.synch();
	tmpMat.flagGPU();

	// future : error handling

	matrix_matrix_sub( 
		tmpMat.getGpuPtr(), B.getGpuPtr(), getRow(), getCol());
	return tmpMat;
}

/*
template <typename TElem, typename TInt>
Matrix<TElem, TInt> Matrix<TElem, TInt>::operator*(Matrix& B)
{
	Matrix<TElem, TInt> tmpMat = this->copy();
	B.synch();
	tmpMat.flagGPU();

	// future : error handling

	matrix_matrix_mult(
		tmpMat.getGpuPtr(), B.getGpuPtr(), getRow(), getCol());
	return tmpMat;
}
*/

template <typename TElem, typename TInt>
TElem& Matrix<TElem, TInt>::operator()(const TInt _nRow, const TInt _nCol)
{
	this->flagCPU();
	
	if (_nRow < 0 || _nCol < 0 || _nRow >= nRow || _nCol >= nCol ) {
		std::cerr << " cusp error : " 
			<< " failure with out of bounds" 
			<< std::endl;
		exit(EXIT_FAILURE);
	} // future : error handling 
	
	TElem *a = this->getCpuPtr();
	return (TElem &)a[_nRow*nCol + _nCol];
}

template <typename TElem, typename TInt>
void Matrix<TElem, TInt>::print()
{
	this->flagCPU();

	const TElem *cpuPtr = this->getCpuPtr();
	for (int i=0;i<nRow; i++) {
		for (int j=0;j<nCol; j++) {
			std::cout << cpuPtr[i*nCol + j] << " ";
		}
		std::cout << std::endl;
	}
}

}

#include "cuspMatrix.tpp"
