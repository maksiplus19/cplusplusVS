#include <string>
#include <vector>

class Sales_data
{
	std::string f;
public:
	Sales_data(std::string s) : f(s) {};
	Sales_data& combine(Sales_data) { return *this; };
	Sales_data& combine(Sales_data&);
	Sales_data& combine(const Sales_data&) const;
};

void N48()
{
	std::string null_isbn("9-999-99999-9");
	Sales_data item1(null_isbn);			// вызов конструктора Sales_data(std::string)
	Sales_data item2("9-999-99999-9");	// сначала будет создан временный объект std::string, а затем вызван Sales_data(std::string)
	// при€вном конструкторе ничего не изменитс€
}

void N49()
{
	// std::string s;
	// Sales_data i;
	// i.combine(s);
	//Sales_data &combine(Sales_data);				// s не€вно приведЄтс€ к Sales_data
	//Sales_data &combine(Sales_data&);				// ошибка требуетс€ l-value
	//Sales_data &combine(const Sales_data&) const;	// тоже самое
}

void N50()
{
	// explicit Person(std::istream &is) { read(is, *this); }
}

void N51()
{
	// int getSize(const std::vector<int>&);
	// getSize(34); 34 может не €вно привестись к вектору
}

void N52()
{
	// не придумал ошибок
}

void N53(){}

class Debug
{
	bool hw, io, other;
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {};
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {};
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }
};

void N54()
{
	// в стандарте 11 constexpr методы не€вно имеют модификатор const
	// в стандарте 14 уже нет
}

void N55()
{
	// нет, т.к. строка не €вл€етс€ литеральным типом
}

void N56(){}
class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double newRate) { interestRate = newRate; }
private:
	std::string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 42.42;
	static double initRate() { return todayRate; }
};

void N58()
{
	auto vecSize = 0;
	static std::vector<double> vec(vecSize); // нельз€ указывать резмер вектора в объ€влении класса
}



int main(int argc, char* argv[])
{
	return 0;
}
