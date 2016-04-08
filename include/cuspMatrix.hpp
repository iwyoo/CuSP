#pragma once

#include "cuspSmartPointer.hpp"

namespace cusp {

template <typename TElem, typename TInt>
class Matrix : public SmartPointer<TElem, TInt> {
	public:
		Matrix(TInt _nRow, TInt _nCol, TElem *_cpuPtr, TElem *_gpuPtr=NULL);
		Matrix<TElem, TInt> copy();

		Matrix operator+(Matrix& B);
		Matrix operator-(Matrix& B);
		Matrix operator*(Matrix& B);
		Matrix& operator+=(Matrix& B);
		Matrix& operator-=(Matrix& B);
		Matrix& operator*=(Matrix& B);
		Matrix operator+(const TElem b);
		Matrix operator-(const TElem b);
		Matrix operator*(const TElem b);
		Matrix operator/(const TElem b);
		Matrix& operator+=(const TElem b);
		Matrix& operator-=(const TElem b);
		Matrix& operator*=(const TElem b);
		Matrix& operator/=(const TElem b);
		TElem& operator()(const TInt _nRow, const TInt _nCol);
		
		void print();
		TInt getRow() const { return nRow; }
		TInt getCol() const { return nCol; }
		
		// future :
		//   dotMult
		//   custumKernelCall

	private:
		TInt nRow;
		TInt nCol;
};

template <typename TElem = float, typename TInt = int>
Matrix<TElem, TInt> zeros(TInt nRow, TInt nCol, TElem *_cpuPtr=NULL);

template <typename TElem = float, typename TInt = int>
Matrix<TElem, TInt> ones(TInt nRow, TInt nCol, TElem *_cpuPtr=NULL);

}
