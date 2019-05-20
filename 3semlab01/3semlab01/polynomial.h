#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
struct monom
{
	T coef;
	int degree;
};

template <typename T>
class polynomial
{
private:
	std::vector<monom<T>> vector;
public:
	void sort();
	void merge();
	void add(const monom<T>& m);

	polynomial& operator+(const polynomial& p);
	polynomial& operator*(const polynomial& p);
	polynomial& operator-(const polynomial& p);
	polynomial& operator/(const polynomial& p);
	polynomial& operator=(const polynomial&) = default;
	polynomial& operator=(polynomial&&) = default;

	polynomial() = default;
	polynomial(const polynomial&) = default;
	polynomial(polynomial&&) = default;
	~polynomial() = default;
};

template <typename T>
void polynomial<T>::sort()
{
	std::sort(vector.begin(), vector.end(), [](monom<T> a, monom<T> b) {return a.degree > b.degree; });
}

template <typename T>
void polynomial<T>::merge()
{
	bool merging = false;
	for (auto it = vector.begin(); it != vector.end() - 1; ++it)
	{
		if (merging) 
		{
			merging = false;
			--it;
		}
		auto next = std::next(it);
		if (it->degree == next->degree)
		{
			it->coef += next->coef;
			vector.erase(next);
		}
	}
}

template <typename T>
void polynomial<T>::add(const monom<T>& m)
{
	vector.push_back(m);
}

template <typename T>
polynomial<T>& polynomial<T>::operator+(const polynomial& p)
{
	polynomial<T> res = *this;
	for (auto && m : p)
	{
		res.add(m);
	}

	res.sort();
	res.merge();

	return res;
}

template <typename T>
polynomial<T>& polynomial<T>::operator*(const polynomial& p)
{

}

template <typename T>
polynomial<T>& polynomial<T>::operator-(const polynomial& p)
{
	polynomial<T> res = *this;
	for (auto && m : p)
	{
		m.coef *= -1;
		res.add(m);
	}

	res.sort();
	res.merge();

	return res;
}

