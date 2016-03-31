#CuSP 

### CUDA Smart Pointer object library 
- example
```
if ( scope ) {
    // in a scope

    auto a = ones(10,10); // automatically GPU memory allocated
    a *= 10;              // automatically GPU computes the result.

} // automatically GPU memroy freed
```
