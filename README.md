#CuSP 

### CUDA Smart Pointer object library 
- example
```
if ( condition ) { 
	// in a scope

    auto a = ones(2,2); // automatically GPU memories are allocated.
    a *= 5;            // automatically GPU computes the result.

	auto b = a*2;

	b(0,0) = 3;
	b.print();

	// it prints,
	//
	// 3 5
	// 5 5
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
