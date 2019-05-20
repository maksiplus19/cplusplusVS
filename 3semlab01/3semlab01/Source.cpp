#include "fraction.h"
#include <stdlib.h>
#include <iostream>
#include "matrix.h"
#include <fstream>
#include "polynomial.h"

int main()
{
	/*fraction<int> f(6, 2), f2(10, 53);
	fraction<int> r3 = f + f2;
	std::cout << r3;
	matrix<fraction<int>, 3> m;
	std::fstream file;
	file.open("Text.txt");
	std::cout << (file.is_open() ? "open" : "not open");
	file >> m;
	file.close();
	std::cout << std::endl;
	std::cout << m;
	std::cout << std::endl << std::endl;
	std::cout << m.revered_matrix();
	std::cout << std::endl;
	std::cout << m;
	std::cout << std::endl;*/

	fraction<double> f(24.2, -48.4);
	std::cout << f << std::endl;
	polynomial<int> p;

	system("pause");
	return 0;
}
