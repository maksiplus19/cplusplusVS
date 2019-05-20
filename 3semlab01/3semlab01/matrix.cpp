#include "matrix.h"


//template <typename T>
//matrix<T> matrix<T>::operator+(const matrix& left)
//{
//	if (this->size != left.size)
//	{
//		std::cout << "ATTENTION : Size of matrix doesn't match";
//		exit(-1);
//	}
//	matrix result(this->size);
//	for (int i = 0; i < left.size - 1; ++i)
//	{
//		for (int j = 0; j < left.size - 1; ++j)
//		{
//			result.m[i][j] = this->m[i][j] + left.matrix[i][j];
//		}
//	}
//	return result;
//}

//template <typename T>
//matrix<T>& matrix<T>::operator-(const matrix& left)
//{
//	if (this->size != left.size)
//	{
//		std::cout << "ATTENTION : Size of matrix doesn't match";
//		exit(-1);
//	}
//	matrix result(this->size);
//	for (int i = 0; i < left.size - 1; ++i)
//	{
//		for (int j = 0; j < left.size - 1; ++j)
//		{
//			result.m[i][j] = this->m[i][j] - left.matrix[i][j];
//		}
//	}
//	return result;
//}

//template <typename T>
//matrix<T> matrix<T>::operator*(const matrix& right)
//{
//	matrix result(this->size);
//	for (int i = 0; i < this->size; ++i)
//	{
//		for (int j = 0; j < this->size; ++j)
//		{
//			for (int k = 0; k < this->size; ++k)
//			{
//				result[i][j] += this[i][k] * right[k][j];
//			}
//		}
//	}
//	return result;
//}

//template <typename T>
//matrix<T>::matrix(int s)
//{
//	this->size = s;
//	this->m.size(s);
//	for (std::vector<T> v : this->m)
//	{
//		v.size(s);
//	}
//}

