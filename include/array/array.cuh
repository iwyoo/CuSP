#pragma once

namespace cusp {

template <typename TElem = float, typename TInt = unsigned int>
__global__ void assignWithAdd(TElem *a, const TElem b);

}
