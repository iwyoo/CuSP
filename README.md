#CuSP 

### CUDA Smart Pointer object library 
- example
```
if ( scope ) {
    // in a scope

    auto a = ones(10,10); // automatically GPU memories are allocated.
    a *= 10;              // automatically GPU computes the result.

} // automatically GPU memories are freed.
```
