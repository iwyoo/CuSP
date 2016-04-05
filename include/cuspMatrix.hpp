#pragma once

#include "cuspSmartPointer.hpp"

namespace cusp {

template <typename TElem, typename TInt>
class Matrix : public SmartPointer<TElem, TInt> {
	public:
		Matrix(TInt row, TInt col, TElem *_cpuPtr, 
			TInt _elemNum, bool _deepCopy=false);

		//Matrix operator+(const Matrix B);
		//Matrix operator-(const Matrix B);
		//Matrix operator*(const Matrix B);
		//Matrix& operator+=(const Matrix B);
		//Matrix& operator-=(const Matrix B);
		//Matrix& operator*=(const Matrix B);
		//Matrix operator+(const TElem b);
		//Matrix operator-(const TElem b);
		//Matrix operator*(const TElem b);
		//Matrix operator/(const TElem b);
		Matrix& operator+=(const TElem b);
		Matrix& operator-=(const TElem b);
		Matrix& operator*=(const TElem b);
		Matrix& operator/=(const TElem b);
		TElem& operator()(const TInt _row, const TInt _col);

		// future :
		//   dotMult
		//   custumKernelCall
		
		void print();
		TInt getRow() const { return row; }
		TInt getCol() const { return col; }
		
	private:
		TInt row;
		TInt col;
};

template <typename TElem = float, typename TInt = unsigned int>
Matrix<TElem, TInt> ones(TInt row, TInt col, TElem *_cpuPtr=NULL);

template <typename TElem = float, typename TInt = unsigned int>
Matrix<TElem, TInt> zeros(TInt row, TInt col, TElem *_cpuPtr=NULL);
}
