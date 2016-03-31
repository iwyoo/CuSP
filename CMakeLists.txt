project (cusp)
cmake_minimum_required(VERSION 2.8.11)

set(CUSP_VERSION 0.0.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++11")
find_package(CUDA REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#set(CMAKE_BUILD_TYPE Release)
#add_library(cusp SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/)
