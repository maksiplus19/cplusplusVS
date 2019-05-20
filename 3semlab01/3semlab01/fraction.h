#pragma once
#include <iostream>

template <typename T>
class fraction
{
private:
	T numertor;
	T denominator;
	void check();
public:
	double value();
	fraction operator*(const fraction& f);
	fraction operator+(const fraction& f);
	fraction operator-(const fraction& f);
	fraction operator/(const fraction& f);

	friend std::ostream& operator<<(std::ostream& stream, const fraction& f)
	{
		stream << "(" << f.numertor << "/" << f.denominator << ")";
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, fraction& f)
	{
		stream >> f.numertor >> f.denominator;
		return stream;
	}

	fraction() = default;
	fraction(T n, T d);
	~fraction() = default;
};

template <typename T>
fraction<T>::fraction(T n, T d)
{
	this->numertor = n;
	this->denominator = d;
	this->check();
}

template <typename T>
fraction<T> fraction<T>::operator+(const fraction& f)
{
	fraction result;
	if (this->denominator == f.denominator)
	{
		result.numertor = this->numertor + f.numertor;
		result.denominator = this->denominator;
	}
	else
	{
		result.denominator = this->denominator * f.denominator;
		result.numertor = this->numertor*f.denominator + f.numertor*this->denominator;
	}
	result.check();
	return result;
}

template <typename T>
fraction<T> fraction<T>::operator-(const fraction& f)
{
	fraction tmp = f;
	tmp.numertor *= -1;
	fraction result = *this + tmp;
	result.check();
	return result;
}

template <typename T>
fraction<T> fraction<T>::operator/(const fraction& f)
{
	fraction result;
	result.numertor = this->numertor*f.denominator;
	result.denominator = this->denominator*f.numertor;
	result.check();
	return result;
}

template <typename T>
void fraction<T>::check()
{
	if (denominator == 0)
	{
		std::cout << "ATTENTION : Detected division by zero" << std::endl;
		exit(-1);
	}
	if ((numertor < 0) && (denominator < 0))
	{
		numertor *= -1;
		denominator *= -1;
	}
	if ((numertor > 0) && (denominator < 0))
	{
		numertor *= -1;
		denominator *= -1;
	}

	T n = abs(numertor), d = abs(denominator);
	while (n != d) n > d ? n -= d : d -= n;
	numertor /= n;
	denominator /= d;
}

template<typename T>
double fraction<T>::value()
{
	return static_cast<double>(this->numertor) / this->denominator;
}

template <typename T>
fraction<T> fraction<T>::operator*(const fraction& f)
{
	fraction result;
	result.numertor = this->numertor*f.numertor;
	result.denominator = this->denominator*f.denominator;
	result.check();
	return result;
}
