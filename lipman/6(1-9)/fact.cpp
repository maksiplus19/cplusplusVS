#include "Chapter6.h"

unsigned long long fact(int n)
{
	unsigned long long res = 1;
	for (int i = 2; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}

unsigned int N5(int n)
{
	return n > 0 ? n : -n;
}

int N7()
{
	static int i = 0;
	return i++;
}
