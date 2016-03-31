#include <cstdarg>

namespace cusp {

template < typename TInt, unsigned int nDim, typename... Args>
Dim<TInt,nDim>::Dim(TInt n, Args... args)
{
	std::va_list args;
	std::va_start(args, n);
	for (int i=0; i<n; i++)
		dimSize[i] = std::var_arg(args, TInt);
	std::va_end(args);
}

}
