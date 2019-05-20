#include "record.h"
#include <iostream>
#include <utility>
#include <vector>


std::string record::get_name() const
{
	return this->name;
}

std::string record::get_surname() const
{
	return this->surname;
}

std::string record::get_patronymic() const
{
	return  this->patronymic;
}

std::string record::get_number() const
{
	return this->number;
}

std::string record::get_email() const
{
	return this->email;
}

std::string record::get_company() const
{
	return this->company;
}

std::string record::get_job() const
{
	return this->job;
}

bool record::operator==( const record& right) const
{
	if (name != right.name) return false;
	if (surname != right.surname) return false;
	if (patronymic != right.patronymic) return false;
	if (number != right.number) return false;
	if (email != right.email) return false;
	if (company != right.company) return false;
	if (job != right.job) return false;
	return true;
}

bool record::operator!=(const record& right) const
{
	return !(*this == right);
}

record& record::operator=(record&& rec) noexcept
{
	std::swap(name, rec.name);
	std::swap(surname, rec.surname);
	std::swap(patronymic, rec.patronymic);
	std::swap(number, rec.number);
	std::swap(email, rec.email);
	std::swap(company, rec.company);
	std::swap(job, rec.job);
	std::cout << "------------ Execute move assignment record ------------" << std::endl;
	return *this;
}

bool record::contain(const std::string& s) const
{
	std::string rec = static_cast<std::string>(*this);
	return rec.find(s) != std::string::npos;
}

record::operator std::string() const
{
	if (!*this) return "";
	std::string str = '\n' + surname + " " + name + " " + patronymic + "\n";
	str += number + '\t' + email + '\n';
	str += company + " " + job + '\n';
	return str;
}

record::operator bool() const
{
	if (name.empty()) return false;
	if (surname.empty()) return false;
	if (patronymic.empty()) return false;
	if (number.empty()) return false;
	if (email.empty()) return false;
	if (company.empty()) return false;
	if (job.empty()) return false;
	return true;
}

record::record(std::string name, std::string surname, std::string patronymic, std::string number, std::string email,
	std::string company, std::string job) :name(std::move(name)), surname(std::move(surname)), patronymic(
		                                       std::move(patronymic)), number(std::move(number)), 
											email(std::move(email)), company(std::move(company)), job(std::move(job)) {}

record::record(record&& rec) noexcept
{
	std::swap(name, rec.name);
	std::swap(surname, rec.surname);
	std::swap(patronymic, rec.patronymic);
	std::swap(number, rec.number);
	std::swap(email, rec.email);
	std::swap(company, rec.company);
	std::swap(job, rec.job);
	std::cout << "------------ Execute move constructor record ------------" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const record& rec)
{
	stream << static_cast<std::string>(rec);
	return stream;
}

std::istream& operator>>(std::istream& stream, record& rec)
{
	stream >> rec.surname >> rec.name >> rec.patronymic >> rec.number >> rec.email >> rec.company >> rec.job;
	return stream;
}
