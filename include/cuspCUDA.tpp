#include "cuspCUDA.hpp"

namespace cusp {

template void matrix_element_add<char, int> 
	(char *a, char b, int row, int col);
template void matrix_element_add<char, unsigned int> 
	(char *a, char b, unsigned int row, unsigned  int col);
template void matrix_element_add<char, unsigned long long> 
	(char *a, char b, unsigned long long row, unsigned long long col);
template void matrix_element_add<short, int> 
	(short *a, short b, int row, int col);
template void matrix_element_add<short, unsigned int> 
	(short *a, short b, unsigned int row, unsigned  int col);
template void matrix_element_add<short, unsigned long long> 
	(short *a, short b, unsigned long long row, unsigned long long col);
template void matrix_element_add<int, int> 
	(int *a, int b, int row, int col);
template void matrix_element_add<int, unsigned int> 
	(int *a, int b, unsigned int row, unsigned  int col);
template void matrix_element_add<int, unsigned long long> 
	(int *a, int b, unsigned long long row, unsigned long long col);
template void matrix_element_add<float, int> 
	(float *a, float b, int row, int col);
template void matrix_element_add<float, unsigned int> 
	(float *a, float b, unsigned int row, unsigned  int col);
template void matrix_element_add<float, unsigned long long> 
	(float *a, float b, unsigned long long row, unsigned long long col);
template void matrix_element_add<double, int> 
	(double *a, double b, int row, int col);
template void matrix_element_add<double, unsigned int> 
	(double *a, double b, unsigned int row, unsigned  int col);
template void matrix_element_add<double, unsigned long long> 
	(double *a, double b, unsigned long long row, unsigned long long col);

template void matrix_element_sub<char, int> 
	(char *a, char b, int row, int col);
template void matrix_element_sub<char, unsigned int> 
	(char *a, char b, unsigned int row, unsigned  int col);
template void matrix_element_sub<char, unsigned long long> 
	(char *a, char b, unsigned long long row, unsigned long long col);
template void matrix_element_sub<short, int> 
	(short *a, short b, int row, int col);
template void matrix_element_sub<short, unsigned int> 
	(short *a, short b, unsigned int row, unsigned  int col);
template void matrix_element_sub<short, unsigned long long> 
	(short *a, short b, unsigned long long row, unsigned long long col);
template void matrix_element_sub<int, int> 
	(int *a, int b, int row, int col);
template void matrix_element_sub<int, unsigned int> 
	(int *a, int b, unsigned int row, unsigned  int col);
template void matrix_element_sub<int, unsigned long long> 
	(int *a, int b, unsigned long long row, unsigned long long col);
template void matrix_element_sub<float, int> 
	(float *a, float b, int row, int col);
template void matrix_element_sub<float, unsigned int> 
	(float *a, float b, unsigned int row, unsigned  int col);
template void matrix_element_sub<float, unsigned long long> 
	(float *a, float b, unsigned long long row, unsigned long long col);
template void matrix_element_sub<double, int> 
	(double *a, double b, int row, int col);
template void matrix_element_sub<double, unsigned int> 
	(double *a, double b, unsigned int row, unsigned  int col);
template void matrix_element_sub<double, unsigned long long> 
	(double *a, double b, unsigned long long row, unsigned long long col);

template void matrix_element_mult<char, int> 
	(char *a, char b, int row, int col);
template void matrix_element_mult<char, unsigned int> 
	(char *a, char b, unsigned int row, unsigned  int col);
template void matrix_element_mult<char, unsigned long long> 
	(char *a, char b, unsigned long long row, unsigned long long col);
template void matrix_element_mult<short, int> 
	(short *a, short b, int row, int col);
template void matrix_element_mult<short, unsigned int> 
	(short *a, short b, unsigned int row, unsigned  int col);
template void matrix_element_mult<short, unsigned long long> 
	(short *a, short b, unsigned long long row, unsigned long long col);
template void matrix_element_mult<int, int> 
	(int *a, int b, int row, int col);
template void matrix_element_mult<int, unsigned int> 
	(int *a, int b, unsigned int row, unsigned  int col);
template void matrix_element_mult<int, unsigned long long> 
	(int *a, int b, unsigned long long row, unsigned long long col);
template void matrix_element_mult<float, int> 
	(float *a, float b, int row, int col);
template void matrix_element_mult<float, unsigned int> 
	(float *a, float b, unsigned int row, unsigned  int col);
template void matrix_element_mult<float, unsigned long long> 
	(float *a, float b, unsigned long long row, unsigned long long col);
template void matrix_element_mult<double, int> 
	(double *a, double b, int row, int col);
template void matrix_element_mult<double, unsigned int> 
	(double *a, double b, unsigned int row, unsigned  int col);
template void matrix_element_mult<double, unsigned long long> 
	(double *a, double b, unsigned long long row, unsigned long long col);

template void matrix_element_div<char, int> 
	(char *a, char b, int row, int col);
template void matrix_element_div<char, unsigned int> 
	(char *a, char b, unsigned int row, unsigned  int col);
template void matrix_element_div<char, unsigned long long> 
	(char *a, char b, unsigned long long row, unsigned long long col);
template void matrix_element_div<short, int> 
	(short *a, short b, int row, int col);
template void matrix_element_div<short, unsigned int> 
	(short *a, short b, unsigned int row, unsigned  int col);
template void matrix_element_div<short, unsigned long long> 
	(short *a, short b, unsigned long long row, unsigned long long col);
template void matrix_element_div<int, int> 
	(int *a, int b, int row, int col);
template void matrix_element_div<int, unsigned int> 
	(int *a, int b, unsigned int row, unsigned  int col);
template void matrix_element_div<int, unsigned long long> 
	(int *a, int b, unsigned long long row, unsigned long long col);
template void matrix_element_div<float, int> 
	(float *a, float b, int row, int col);
template void matrix_element_div<float, unsigned int> 
	(float *a, float b, unsigned int row, unsigned  int col);
template void matrix_element_div<float, unsigned long long> 
	(float *a, float b, unsigned long long row, unsigned long long col);
template void matrix_element_div<double, int> 
	(double *a, double b, int row, int col);
template void matrix_element_div<double, unsigned int> 
	(double *a, double b, unsigned int row, unsigned  int col);
template void matrix_element_div<double, unsigned long long> 
	(double *a, double b, unsigned long long row, unsigned long long col);

template void matrix_matrix_add<char, int> 
	(char *a, char *b, int row, int col);
template void matrix_matrix_add<char, unsigned int> 
	(char *a, char *b, unsigned int row, unsigned int col);
template void matrix_matrix_add<char, unsigned long long> 
	(char *a, char *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_add<short, int> 
	(short *a, short *b, int row, int col);
template void matrix_matrix_add<short, unsigned int> 
	(short *a, short *b, unsigned int row, unsigned int col);
template void matrix_matrix_add<short, unsigned long long> 
	(short *a, short *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_add<int, int> 
	(int *a, int *b, int row, int col);
template void matrix_matrix_add<int, unsigned int> 
	(int *a, int *b, unsigned int row, unsigned int col);
template void matrix_matrix_add<int, unsigned long long> 
	(int *a, int *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_add<float, int> 
	(float *a, float *b, int row, int col);
template void matrix_matrix_add<float, unsigned int> 
	(float *a, float *b, unsigned int row, unsigned int col);
template void matrix_matrix_add<float, unsigned long long> 
	(float *a, float *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_add<double, int> 
	(double *a, double *b, int row, int col);
template void matrix_matrix_add<double, unsigned int> 
	(double *a, double *b, unsigned int row, unsigned int col);
template void matrix_matrix_add<double, unsigned long long> 
	(double *a, double *b, unsigned long long row, unsigned long long col);

template void matrix_matrix_sub<char, int> 
	(char *a, char *b, int row, int col);
template void matrix_matrix_sub<char, unsigned int> 
	(char *a, char *b, unsigned int row, unsigned int col);
template void matrix_matrix_sub<char, unsigned long long> 
	(char *a, char *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_sub<short, int> 
	(short *a, short *b, int row, int col);
template void matrix_matrix_sub<short, unsigned int> 
	(short *a, short *b, unsigned int row, unsigned int col);
template void matrix_matrix_sub<short, unsigned long long> 
	(short *a, short *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_sub<int, int> 
	(int *a, int *b, int row, int col);
template void matrix_matrix_sub<int, unsigned int> 
	(int *a, int *b, unsigned int row, unsigned int col);
template void matrix_matrix_sub<int, unsigned long long> 
	(int *a, int *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_sub<float, int> 
	(float *a, float *b, int row, int col);
template void matrix_matrix_sub<float, unsigned int> 
	(float *a, float *b, unsigned int row, unsigned int col);
template void matrix_matrix_sub<float, unsigned long long> 
	(float *a, float *b, unsigned long long row, unsigned long long col);
template void matrix_matrix_sub<double, int> 
	(double *a, double *b, int row, int col);
template void matrix_matrix_sub<double, unsigned int> 
	(double *a, double *b, unsigned int row, unsigned int col);
template void matrix_matrix_sub<double, unsigned long long> 
	(double *a, double *b, unsigned long long row, unsigned long long col);
}
