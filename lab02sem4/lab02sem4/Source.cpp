#include "binary_tree.h"
#include <algorithm>
template<typename T>
void all(std::list<T> l)
{
	for (auto el : l)
	{
		std::cout << el << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	binary_tree<int> tree;

	for (int i = 0; i < 10; ++i)
	{
		int n = rand() % 100;
		std::cout << n << ' ';
		tree.add(n);
	}
	std::cout << std::endl;
	std::cout << "size = " << tree.all().size() << std::endl;

	std::list<int> l = tree.counting(2);
	l = tree.counting(2);
	l = tree.counting(2);

	all(tree.all());

	l = tree.counting(2);
	l = tree.counting(2);

	all(tree.all());


	//std::cout << "size = " << l.size() + all.size() << std::endl;
	char c;
	std::cin >> c;
	return 0;

	//auto p = new node<int>(4, nullptr), n = new node<int>(5, p), c = new node<int>(6, n);
	//p->set_right(n);
	//n->set_right(c);
	//delete n;
}
