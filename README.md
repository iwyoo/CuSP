#CuSP 

### CUDA Smart Pointer object library 
- example
```cpp
#include <cusp>
...
if ( condition ) { 
	// in a scope

	// automatically GPU memories are allocated.
    auto a = cusp::ones(2,2); 

	// automatically GPU computes the result.
    a *= 3;            		  

	auto b = a*2;
	b(0,0) = 3;
	b.print();

	// it prints,
	//
	// 3 6
	// 6 6
	//

} // automatically GPU memories are freed.
```

###  How to install

To install CuSP, you need
- cmake (>=2.8)
- nvcc
- c++ compiler supporting c++11 features.

```
mkdir build
cd build
cmake ..
make
sudo make install
```
