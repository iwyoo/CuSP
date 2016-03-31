#include <cassert>
#include <Array/Array.hpp>

namespace std {

template <typename TElem, typename TInt, unsigned int nDim, typename ...Dims>
array<TElem,TInt,nDim>::array zeros(Dims... _dims)
{
	static_assert(std::is_all_same<TInt, Dims...>::value, 
		"Type doesn't match. Each dimension value type must be TInt.");
	TInt dims[nDim] = {_dims...};
	TInt elemNum = 1;
	Shape<TInt,nDim> shape;
	for (int i=0; i<nDim; i++) { 
		assert(dims[i] > 0);
		shape[i] = dims[i];
		elemNum *= dims[i];
	}

	TElem *cpuPtr = new TElem[elemNum];
	for (int i=0; i<elemNum; i++) cpuPtr[i] = 0;
	return array(cpuPtr, elemNum, shape, true);
}

}
