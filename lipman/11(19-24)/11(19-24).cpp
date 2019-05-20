#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <string>

class Sales_data;

void N19()
{
	using compareType = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
	std::multiset<Sales_data, compareType> bookstore;
	std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
}

void N20()
{
	std::map<std::string, size_t> counts;
	for (std::string word; std::cin >> word;)
	{
		auto result = counts.insert({ word, 1 });
		if (!result.second)
			++result.first->second;
	}
	for (auto const& count : counts)
		std::cout << count.first << " " << count.second << ((count.second > 1) ? " times\n" : " time\n");
}

void N21()
{
	// пока идет чтение
	// если слово есть в контейнере, то увеличить счетчик на 1
	// иначе добавить и установить счетчик на 1
	// проще говоря цикл подсчитывает количесво раз которое было введо каждое слово
}

void N22()
{
	// std::pair<std::string, std::vector<int>>    // argument
	// std::pair<std::map<std::string, std::vector<int>>::iterator, bool> // return
}

void N23()
{
	std::multimap<std::string, std::string> families;
	for (std::string lname, cname; std::cin >> cname >> lname; families.emplace(lname, cname));
	for (auto const& family : families)
		std::cout << family.second << " " << family.first << std::endl;
}

void N24()
{
	// map<int, int> m;
	// m[0] = 1;
	// добавляет пару { 0, 1 } в m
}

int main(int argc, char* argv[])
{
	return 0;
}
