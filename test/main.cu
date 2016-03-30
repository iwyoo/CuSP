#include "SmartPointer.hpp"
#include "SharedData.hpp"

int main()
{
	float *a = new float[10];
	for (int i=0; i<10; i++) a[i] = 1;
	cusp::SmartPointer<> sp(a, 10);
}
