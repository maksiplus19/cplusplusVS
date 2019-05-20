#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <iterator>

void N22()
{
	/*
	 *  using std::string;
		using namespace std::placeholders;

		bool isLesserThanOrEqualTo6(const string &s, string::size_type sz)
		{
		    return s.size() <= sz;
		}

		int main()
		{
		    std::vector<string> authors{ "Mooophy", "pezy", "Queequeg90", "shbling", "evan617" };
		    std::cout << count_if(authors.cbegin(), authors.cend(), bind(isLesserThanOrEqualTo6, _1, 6));
		}
	 */
}

void N23()
{
	// n+1 
	// сама функция и n её аргументов
}

auto check_size(std::string const& str, size_t sz)
{
	return str.size() < sz;
}
void N24()
{
	std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
	std::string str("123456");
	auto result = find_if(vec.begin(), vec.end(), bind(check_size, str, std::placeholders::_1));
	if (result != vec.cend())
		std::cout << *result << std::endl;
	else
		std::cout << "Not found" << std::endl;
}

using std::string; using std::vector;
using namespace std::placeholders;

void elimdups(vector<string> &vs)
{
	std::sort(vs.begin(), vs.end());
	vs.erase(unique(vs.begin(), vs.end()), vs.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimdups(words);
	auto iter = std::stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
	for_each(words.begin(), iter, [](const string &s) { std::cout << s << " "; });
}
void N25()
{
	std::vector<std::string> v{	"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(v, 4);	 
}

void N26()
{
	//back_inserter использует push_back.
	//front_inserter использует push_front.
	//insert использует insert
}

void N27()
{
	std::vector<int> vec{ 1, 1, 3, 3, 5, 5, 7, 7, 9 };
	std::list<int> lst;

	std::unique_copy(vec.begin(), vec.end(), back_inserter(lst));
	for (auto i : lst)
		std::cout << i << " ";
	std::cout << std::endl;
}

using std::list; using std::copy; using std::cout; using std::endl;

template<typename Sequence>
void print(Sequence const& seq)
{
	for (const auto& i : seq)
		std::cout << i << " ";
	std::cout << std::endl;
}
void N28()
{
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// uses inserter
	list<int> lst1;
	copy(vec.cbegin(), vec.cend(), inserter(lst1, lst1.begin()));
	print(lst1);

	// uses back_inserter
	list<int> lit2;
	copy(vec.cbegin(), vec.cend(), back_inserter(lit2));
	print(lit2);

	// uses front_inserter
	list<int> lst3;
	copy(vec.cbegin(), vec.cend(), front_inserter(lst3));
	print(lst3);
}

int main(int argc, char* argv[])
{
	N27();
	return 0;
}
