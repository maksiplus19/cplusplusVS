
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

void N17()
{
	std::vector<std::string> v;
	std::string s="s";
	while (true)
	{
		std::cin >> s;
		if (s=="0") break;
		std::for_each(s.begin(), s.end(), [&](char& c) { c += toupper(c); });
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if (i%8 == 0) std::cout << std::endl;
		std::cout << v[i] << " ";
	}
}

void N18()
{
	std::vector<int> v;
	v[0] = 42; 
	// Ќе корретно. ƒл€ коректно работы необходимо объ€вить вектор std::vector<int> v(1); или после объ€вллени€ v.resize(1);
}

void N19()
{
	std::vector<int> v(10);
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = 42;
	}
	for (int& i : v)
	{
		i = 42;
	}
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		*it = 42;
	}
}

void N20()
{
	std::vector<int> v;
	int n = 1;
	while(true)
	{
		std::cin >> n;
		if (!n) break;
		v.push_back(n);
	}
	for (int i : v)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	for (int i = 0; i < v.size() - 1; ++i)
	{
		std::cout << v[i] + v[i + 1] << ' ';
	}
	std::cout << std::endl;
	for (int i = 0; i < v.size() / 2; ++i)
	{
		std::cout << v[i] + v[v.size() - 1 - i] << ' ';
	}
	std::cout << std::endl;
}

void N21()
{
	std::vector<int> v;
	int n = 1;
	while (true)
	{
		std::cin >> n;
		if (!n) break;
		v.push_back(n);
	}
	for (int i : v)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	for (auto it = v.begin(); it < v.end() - 1; ++it)
	{
		std::cout << *it + *(it + 1) << ' ';
	}
	std::cout << std::endl;
	for (auto it = v.begin(), it_r = v.end() - 1; it != it_r || it < it_r; ++it, --it_r)
	{
		std::cout << *it + *it_r << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	//N21();
	system("pause");
	return 0;
}
