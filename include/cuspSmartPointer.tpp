#include "cuspSmartPointer.hpp"

namespace cusp {

template class SmartPointer<char, int>;
template class SmartPointer<char, unsigned int>;
template class SmartPointer<char, unsigned long long>;
template class SmartPointer<short, int>;
template class SmartPointer<short, unsigned int>;
template class SmartPointer<short, unsigned long long>;
template class SmartPointer<int, int>;
template class SmartPointer<int, unsigned int>;
template class SmartPointer<int, unsigned long long>;
template class SmartPointer<float, int>;
template class SmartPointer<float, unsigned int>;
template class SmartPointer<float, unsigned long long>;
template class SmartPointer<double, int>;
template class SmartPointer<double, unsigned int>;
template class SmartPointer<double, unsigned long long>;

}
