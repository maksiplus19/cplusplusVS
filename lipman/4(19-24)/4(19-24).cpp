
#include <vector>
#include <string>
#include <iostream>

void N19()
{
	int *ptr;
	std::vector<int> vec;
	int ival = 0;
	//ptr != 0 && *ptr++
	//ival++ && ival				//всегда true
	//vec[ival++] <= vec[ival];
}

void N20()
{
	std::vector<std::string>::iterator iter;
	*iter++;
	//(*iter)++;		//error никремента строки
	//*iter.empty();	//error empty применяется к итератору
	iter->empty();
	//++*iter;			//error инкремента строки
	iter++->empty();
}

void N21()
{
	const int size = 30;
	std::vector<int> v(size);
	for (int i = 0; i < size; ++i)
	{
		v[i] = rand() % size;
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (*it % 2 == 1)
		{
			v.erase(it);
		}
	}
	for (auto el : v)
	{
		std::cout << el << ' ';
	}
	std::cout << std::endl;
}

void N22()
{
	int grade = 96;
	//std::string final_grade = (grade < 60) ? "fail" : "pass";
	//final_grade = (grade > 90) ? "high pass"
	//	: (grade < 60) ? "fail" : "pass";
	std::string final_grade;
	if (grade >= 90) final_grade = "high pass";
	else if (grade >= 75) final_grade = "pass";
	else if (grade > 59) final_grade = "low pass";
	else final_grade = "fail";
	std::cout << final_grade << std::endl << std::endl << std::endl;

	final_grade = grade > 90 ? "high pass" : grade >= 75 ? "pass" : grade > 59 ? "low pass" : "fail";
	std::cout << final_grade << std::endl;
}

void N23()
{
	std::string s = "word";
	std::string p1 = s + s[s.size() - 1] == "s" ? "" : "a";		// оказалось что пример компилируется если вместо 's' написать "s" (ошибка на которую указывет компилятор)
	std::string p11 = s + (s[s.size() - 1] == 's' ? "" : "a");	// видимо то, что имелось ввиду
	std::cout << p1 << std::endl;
}

void N24()
{
	//wat вообще дичь какая-то
}


int main(int argc, char* argv[])
{
	N24();
	//system("pause");
	return 0;
}
