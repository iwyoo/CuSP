#pragma once

#include "cuspSmartPointer.hpp"

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int>
class Matrix : public SmartPointer<TElem, TInt> {
	public:
		Matrix(TInt row, TInt col, TElem *_cpuPtr, TInt _elemNum,
			bool _autoSynch=false, bool _deepCopy=false);

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
		//Matrix& operator-=(const TElem b);
		//Matrix& operator*=(const TElem b);
		//Matrix& operator/=(const TElem b);

		void synch() 
		{ if (gpuDirtyFlag) SmartPointer<TElem, TInt>::synchToCPU(); }
			// future : To GPU synch for CPU-only operation.
		
		// dotMult(); // future
		// print(); // future
		// size(); // future

		TInt getRow() const { return row; }
		TInt getCol() const { return col; }
		
	private:
		TInt row;
		TInt col;
		const bool autoSynch;
		bool gpuDirtyFlag;
			// bool cpuDirtyFlag; // future : For CPU-only operation
};


template <typename TElem = float, typename TInt = unsigned int> 
Matrix<TElem, TInt> ones(TInt row, TInt col, 
		bool autoSynch=false, TElem *_cpuPtr=NULL);

/*
template <typename TElem = float, typename TInt = unsigned int> 
Matrix<TElem, TInt> zeros(TInt row, TInt col,
		bool autoSynch=false, TElem *_cpuPtr=NULL);
*/
}
