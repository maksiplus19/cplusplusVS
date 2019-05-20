#pragma once
#include <vector>
#include <iostream>
#include <fstream>

template <typename T, int size>
class matrix
{
private:
	constexpr static const double delta = 1e-09;
	std::vector<std::vector<T>> m;
public:
	bool is_zero_row(int);
	bool is_zero_column(int);
	int zero_count(int);
	int first_not_zero_row(int);
	matrix<double, size> toDouble();
	double det();
	matrix<double, size> revered_matrix();
	matrix<T, size> transposed_matrix();

	matrix operator+(const matrix<T, size>& right);
	matrix operator-(const matrix<T, size>& right);
	matrix operator*(const matrix& right);
	matrix operator*(const double n);
	std::vector<T>& operator[](int index);

	friend std::ostream& operator<<(std::ostream& stream, const matrix& m)
	{
		for (std::vector<T> line : m.m)
		{
			for (auto el : line)
			{
				stream << el << " ";
			}
			stream << std::endl;
		}
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, matrix& m)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				stream >> m.m[i][j];
				std::cout << m.m[i][j];
			}
		}
		return stream;
	}

	matrix();
	matrix(const matrix&) = default;
	~matrix() = default;
};

template <typename T, int size>
matrix<T, size> matrix<T, size>::operator+(const matrix<T, size>& right)

{
	matrix result;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			result[i][j] = this->m[i][j] + right.m[i][j];
		}
	}
	return result;
}

template <typename T, int size>
matrix<T, size> matrix<T, size>::operator-(const matrix<T, size>& right)

{
	matrix result;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			result[i][j] = this->m[i][j] - right.m[i][j];
		}
	}
	return result;
}

template <typename T, int size>
matrix<T, size> matrix<T, size>::operator*(const matrix& right)

{
	matrix result;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			for (int k = 0; k < size; ++k)
			{
				result[i][j] += this->m[i][k] * right.m[k][j];
			}
		}
	}
	return result;
}

template <typename T, int size>
matrix<T, size> matrix<T, size>::operator*(const double n)
{
	matrix<T, size> res = *this;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			res.m[i][j] *= n;
		}
	}
	return res;
}

template <typename T, int size>
std::vector<T>& matrix<T, size>::operator[](int index)
{
	return this->m[index];
}

template <typename T, int size>
matrix<T, size>::matrix()
{
	this->m.resize(size, std::vector<T>(size));
}

template <typename T, int size>
bool matrix<T, size>::is_zero_row(int row)
{
	for (int i = 0; i < size; ++i)
	{
		if (abs(this->m[row][i]) > delta) return false;
	}
	return true;
}

template <typename T, int size>
bool matrix<T, size>::is_zero_column(int column)
{
	for (int i = 0; i < size; ++i)
	{
		if (abs(this->m[i][column]) > delta) return false;
	}
	return true;
}

template <typename T, int size>
int matrix<T, size>::zero_count(int index)
{
	int res = 0;
	for (int i = index; i < size; ++i)
	{
		if (abs(this->m[i][index]) > delta) ++res;
	}
	return res;
}

template <typename T, int size>
int matrix<T, size>::first_not_zero_row(int index)
{
	for (int i = index; i < size; ++i)
	{
		if (abs(this->m[i][index]) > delta) return i;
	}
	return 0;
}

template <typename T, int size>
matrix<double, size> matrix<T, size>::toDouble()
{
	matrix<double, size> result;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			result.m[i][j] = static_cast<double>(this->m[i][j]);
		}
	}
	return result;
}

template <typename T, int size>
double matrix<T, size>::det()
{
	double det = 1;
	matrix<double, size> doubleMatrix = this->toDouble();

	for (int i = 0; i < size - 1; ++i)
	{
		if (doubleMatrix.is_zero_row(i) || doubleMatrix.is_zero_column(i)) return 0.0;
		if (doubleMatrix.zero_count(i) == size - i - 1) continue;
		if (abs(doubleMatrix.m[i][i]) < delta)
		{
			std::swap(doubleMatrix.m[i], doubleMatrix.m[doubleMatrix.first_not_zero_row(i)]);
			det *= -1;
		}

		for (int j = i + 1; j < size; ++j)
		{
			double koef = doubleMatrix[j][i] / doubleMatrix[i][i];
			for (int k = i; k < size; ++k)
			{
				doubleMatrix[j][k] -= koef * doubleMatrix[i][k];
			}
		}
	}

	for (int i = 0; i < size; ++i)
	{
		det *= doubleMatrix[i][i];
	}
	return abs(det) < delta ? 0 : det;
}

template <typename T, int size>
matrix<double, size> matrix<T, size>::revered_matrix()
{
	if (abs(this->det()) < delta)
	{
		std::cout << "Det = 0. Error";
		exit(-2);
	}
	matrix<double, size> addedMatrix;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix<T, size> tmpMatrix = *this;
			for (int k = 0; k < size; ++k)
			{
				tmpMatrix.m[k].erase(tmpMatrix.m[k].begin() + j);
			}
			tmpMatrix.m.erase(tmpMatrix.m.begin() + i);

			matrix<T, size - 1> res;

			for (int k = 0; k < size - k; ++k)
			{
				for (int l = 0; l < size - 1; ++l)
				{
					res[k][l] = tmpMatrix[k][l];
				}
			}
			addedMatrix[i][j] = res.det() * pow(-1, i + j);
		}
	}
	return addedMatrix.transposed_matrix() * (1.0 / this->det());
}

template <typename T, int size>
matrix<T, size> matrix<T, size>::transposed_matrix()
{
	matrix<T, size> res = *this;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			std::swap(res.m[i][j], res.m[j][i]);
		}
	}
	return res;
}
