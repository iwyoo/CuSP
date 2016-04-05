#include "cuspSharedData.hpp"

namespace cusp {

template class SharedData<char, int>;
template class SharedData<char, unsigned int>;
template class SharedData<char, unsigned long long>;
template class SharedData<short, int>;
template class SharedData<short, unsigned int>;
template class SharedData<short, unsigned long long>;
template class SharedData<int, int>;
template class SharedData<int, unsigned int>;
template class SharedData<int, unsigned long long>;
template class SharedData<float, int>;
template class SharedData<float, unsigned int>;
template class SharedData<float, unsigned long long>;
template class SharedData<double, int>;
template class SharedData<double, unsigned int>;
template class SharedData<double, unsigned long long>;

}
