#include <iostream>
#include <future>
#include <fstream>

char read(int pos)
{
	char res = 0;
	std::ifstream file;
	file.open("Text.txt");
	file.seekg(pos);
	if (file.is_open()) file >> res;
	else return -1;
	file.close();
	return res;
}

void task10()
{
	char res = 1;
	int pos = 0;
	while (res)
	{
		std::future<char> f = std::async(read, pos++);
		res = f.get();
		if (res > 0) std::cout << res;
	}
	std::cout << std::endl;
}

void read_var(char* res, int pos, int size)
{
	//char res = 0;
	std::ifstream file;
	file.open("Text.txt");
	file.seekg(pos);
	if (file.peek() == EOF)
	{
		*res = 0;
		return;
	}
	int i;
	for (i = 0; i < size && file.peek() != EOF; ++i)
	{
		file >> res[i];
	}
	res[i] = 0;
	file.close();
}

void task12()
{
	char res[11] = { 1, 0 };
	int pos = 0;
	while (res[0])
	{
		int len = rand() % 10;
		std::future<void> f = std::async(read_var, res, pos, len);
		pos += len;
		f.wait();
		std::cout << res;
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	task12();
	char a;
	std::cin >> a;
	return 0;
}
