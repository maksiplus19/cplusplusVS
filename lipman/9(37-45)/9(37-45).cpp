#include <iostream>
#include <vector>
#include <string>

class Sales_data;

void N37()
{
	// std::list содержит элементы не последовательно, что не позволяет заранее зерезервировать память
	// std::array содержит неизменяемое количество элементов, что не требует дополнительного выделения памяти
}

void N38()
{
	std::vector<std::string> v;

	for (std::string buffer; std::cin >> buffer; v.push_back(buffer))

		std::cout << v.capacity() << std::endl;
}

void N39()
{
	std::vector<std::string> svec;
	svec.reserve(1024);
	std::string word;
	while (std::cin >> word)
		svec.push_back(word);
	svec.resize(svec.size() + svec.size() / 2);
}

void N40()
{
	// read		size	capacity
	// 256		384		1024
	// 512		768		1024
	// 1000		1500	2000
	// 1048		1572	2048
}

void N41()
{
	std::vector<char> v{ 'p', 'e', 'z', 'y' };
	std::string str(v.cbegin(), v.cend());
	std::cout << str << std::endl;
}

void N42()
{
	// перед чтением вызвать reserve(200);
}

void N43(){}
auto replace_with_43(std::string &s, std::string const& oldVal, std::string const& newVal)
{
	for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); )
		if (oldVal == std::string{ cur, cur + oldVal.size() })
			cur = s.erase(cur, cur + oldVal.size()),
			cur = s.insert(cur, newVal.begin(), newVal.end()),
			cur += newVal.size();
		else
			++cur;
}

void N44(){}
auto replace_with_44(std::string &s, std::string const& oldVal, std::string const& newVal)
{
	for (size_t pos = 0; pos <= s.size() - oldVal.size();)
		if (s[pos] == oldVal[0] && s.substr(pos, oldVal.size()) == oldVal)
			s.replace(pos, oldVal.size(), newVal),
			pos += newVal.size();
		else
			++pos;
}

void N45(){}
auto add_pre_and_suffix(std::string name, std::string const& pre, std::string const& su)
{
	name.insert(name.begin(), pre.cbegin(), pre.cend());
	return name.append(su);
}

int main(int argc, char* argv[])
{
	return 0;
}
