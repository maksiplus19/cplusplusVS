#include <iostream>
#include <string>

void N21()
{
	std::string s1, s2;
	std::cout << "Enter 1 if you want to finish" << std::endl;
	std::cin >> s1;
	while (s1 != "1") {
		std::cin >> s2;
		if (isupper(s2[0]) && s1 == s2) {
			std::cout << std::endl;
			std::cout << s1 << std::endl;
			break;
		}
		std::cin >> s1;
		if (s1 == "1") {
			std::cout << "nooooooooo\n";
		}
	}
}

int get_size()
{
	return rand() - 1000;
}

void N22()
{
	while (true)
	{
		int sz = get_size();
		if (sz > 0) break;
	}
}

void N23()
{
	int a, b;
	std::cin >> a;
	std::cin >> b;
	std::cout << a/b << std::endl;
}

void N24()
{
	int a, b;
	std::cin >> a;
	std::cin >> b;
	if (b == 0) throw std::runtime_error("Divide by zero");
	std::cout << a/b << std::endl;
}

void N25()
{
	int a, b;
	std::cin >> a;
	while(true)
	{
		std::cin >> b;
		try
		{
			if (b == 0) throw std::runtime_error("Divide by zero");
		}
		catch (std::runtime_error e)
		{
			std::cout << e.what() << std::endl;
			std::cout << "Enter second num again" << std::endl;
			continue;
		}
		std::cout << a / b;
		break;
	}
}


int main(int argc, char* argv[])
{
	N25();
	system("pause");
	return 0;
}
