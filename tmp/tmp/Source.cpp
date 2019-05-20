#include <complex>
#include <vector>
#include <algorithm>
#include <iostream>

typedef std::complex<double> base;

void fft(std::vector<base> & a, bool invert)
{
	const auto n = static_cast<int>(a.size());
	if (n == 1) return;
	std::vector<base> a0(n / 2), a1(n / 2); 	
	for (int i = 0, j = 0; i < n; i += 2, ++j)
	{
		a0[j] = a[i];
		a1[j] = a[i + 1];
	} 	
	fft(a0, invert); 	
	fft(a1, invert);
	const double ang = 2 * 3.1415 / n * (invert ? -1 : 1);
	base w(1);
	const base wn(cos(ang), sin(ang));
	for (int i = 0; i < n / 2; ++i)
	{
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i]; 		
		if (invert)
			a[i] /= 2, a[i + n / 2] /= 2; 		
		w *= wn;
	}
}

void multiply(const std::vector<int> & a, const std::vector<int> & b, std::vector<int> & res)
{
	std::vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end()); 	
	size_t n = 1; 	
	while (n < std::max(a.size(), b.size())) 
		n <<= 1; 	
	n <<= 1; 	
	fa.resize(n), fb.resize(n);
	fft(fa, false), fft(fb, false);
	for (size_t i = 0; i < n; ++i) 		
		fa[i] *= fb[i]; 
	fft(fa, true); 
	res.resize(n); 
	for (size_t i = 0; i < n; ++i) 	
		res[i] = int(fa[i].real() + 0.5);
}

int main(int argc, char* argv[])
{
	std::vector<int> a = { 1, 2, 5, 0, 0, 1 }, b = { 1, 2 }, c;
	multiply(a, b, c);
	for (auto v : c)
	{
		std::cout << v << ' ';
	}
	std::cout << std::endl;
	char ch;
	std::cin >> ch;
}
