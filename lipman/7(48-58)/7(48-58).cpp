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
	Sales_data item1(null_isbn);			// ����� ������������ Sales_data(std::string)
	Sales_data item2("9-999-99999-9");	// ������� ����� ������ ��������� ������ std::string, � ����� ������ Sales_data(std::string)
	// �������� ������������ ������ �� ���������
}

void N49()
{
	// std::string s;
	// Sales_data i;
	// i.combine(s);
	//Sales_data &combine(Sales_data);				// s ������ ��������� � Sales_data
	//Sales_data &combine(Sales_data&);				// ������ ��������� l-value
	//Sales_data &combine(const Sales_data&) const;	// ���� �����
}

void N50()
{
	// explicit Person(std::istream &is) { read(is, *this); }
}

void N51()
{
	// int getSize(const std::vector<int>&);
	// getSize(34); 34 ����� �� ���� ���������� � �������
}

void N52()
{
	// �� �������� ������
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
	// � ��������� 11 constexpr ������ ������ ����� ����������� const
	// � ��������� 14 ��� ���
}

void N55()
{
	// ���, �.�. ������ �� �������� ����������� �����
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
	static std::vector<double> vec(vecSize); // ������ ��������� ������ ������� � ���������� ������
}



int main(int argc, char* argv[])
{
	return 0;
}
