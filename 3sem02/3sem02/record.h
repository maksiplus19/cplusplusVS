#pragma once
#include <string>

class record
{
private:
	std::string name;			//имя
	std::string surname;		//фамилия
	std::string patronymic;		//отчество
	std::string number;			//номер
	std::string email;			//почта
	std::string company;		//компания
	std::string job;			//должность
public:
	std::string get_name() const;
	std::string get_surname() const;
	std::string get_patronymic() const;
	std::string get_number() const;
	std::string get_email() const;
	std::string get_company() const;
	std::string get_job() const;

	bool operator==(const record& right) const;
	bool operator!=(const record& right) const;
	record& operator=(const record& rec) = default;
	record& operator=(record&& rec) noexcept;
	friend std::ostream& operator<<(std::ostream& stream, const record& rec);
	friend std::istream& operator>>(std::istream& stream, record& rec);

	bool contain(const std::string&) const;
	operator std::string() const;
	operator bool() const;

	record(std::string name, std::string surname, std::string patronymic, std::string number, 
		   std::string email, std::string company, std::string job);
	record() = default;
	record(const record&) = default;
	record(record&&) noexcept;
	~record() = default;
};

