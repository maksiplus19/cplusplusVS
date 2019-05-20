#include <ostream>
class Sales_data {
	friend std::istream& operator>>(std::istream&, Sales_data&); // input
	friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
	friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition

public:
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) { }
	Sales_data() : Sales_data("", 0, 0.0f) { }
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) { }
	Sales_data(std::istream &is);

	Sales_data& operator+=(const Sales_data&); // compound-assignment
	std::string isbn() const { return bookNo; }

private:
	inline double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

void N9(){}
std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

void N10()
{
	// а - ок
	// b - ошибка. 24.95 будет воспринято как 24 и 0.95
}

void N11()
{
	// нет проверки на ввод
	// ничего не случится
}

void N12()
{
	//std::istream& operator>>(std::istream &in, Book &book)
	//{
	//	in >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
	//	return in;
	//}
}

void N13()
{
	// nothing
}

void N14()
{
	// тогда бы оператор += использовал бы не нужный объект
}

void N15()
{
	//Book operator+(const Book &lhs, const Book &rhs)
	//{
	//	Book book = lhs;
	//	book += rhs;
	//	return book;
	//}
}

void N16()
{
	//bool operator==(const StrBlob &lhs, const StrBlob &rhs)
	//{
	//	return *lhs.data == *rhs.data;
	//}

	//bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
	//{
	//	return !(lhs == rhs);
	//}

	//bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
	//{
	//	return lhs.curr == rhs.curr;
	//}

	//bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
	//{
	//	return !(lhs == rhs);
	//}

	//bool operator==(const String &lhs, const String &rhs)
	//{
	//	return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	//}

	//bool operator!=(const String &lhs, const String &rhs)
	//{
	//	return !(lhs == rhs);
	//}
}