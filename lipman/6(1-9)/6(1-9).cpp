#include <string>
#include <iostream>
#include "Chapter6.h"

void N1()
{
	//��������� �������� ����, ��� �������� �������
	//�������� ����������� ������ ������������ � �������
}

void N2()
{
	//int f() // auto f()
	//{
	//	std::string s;
	//	// ...
	//	return s;
	//}  // ������ ������� string ������ int

	//f2(int i) { /* ... */ }					//auto f2(int i)			// ������ ����������� ��� ������������ ���������
	//int calc (int v1, int v1) { /* ... */ }	// (int v1, int v2)			// ��������� � ����������� �������
	//double square(double x) return x * x;		// { return x * x; }		// ����������� �������� ������
}

//unsigned long long fact(int n)
//{
//	unsigned long long res = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		res *= i;
//	}
//	return res;
//}
//
//unsigned int N5(int n)
//{
//	return n > 0 ? n : -n;
//}
//
//int N7 ()
//{
//	static int i = 0;
//	return i++;
//}

int main(int argc, char* argv[])
{
	//int n;
	//std::cout << "Enter number" << std::endl;
	//std::cin >> n;
	//std::cout << fact(n) << std::endl;
	//std::cout << "-56 " << N5(-56) << std::endl;
	//std::cout << std::endl;
	//std::cout << N7() << " " << N7() << " " << N7() << std::endl;
	std::cout << N7() << std::endl;
	std::cout << N7() << std::endl;
	std::cout << N7() << std::endl;
	return 0;
}
