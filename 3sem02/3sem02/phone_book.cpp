#include "phone_book.h"
#include <fstream>


void phone_book::add_record(const record& rec)
{
	table.insert(rec.get_number(), rec);
}

void phone_book::add_record(std::string name, std::string surname, std::string patronymic, std::string number,
	std::string email, std::string company, std::string job)
{
	table.insert(number, record(name, surname, patronymic, number, email, company, job));
}

std::vector<record> phone_book::find_by_substr(std::string s)
{
	std::vector<record>	v;
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		if ((*it).contain(s)) 
			v.push_back(*it);
	}
	return v;
}

bool phone_book::contain(const record& rec)
{
	auto it = table.find(rec.get_number(), rec);
	if (it != this->end()) return static_cast<bool>(*table.find(rec.get_number(), rec));
	return false;	
}

record& phone_book::get_record(const record& rec)
{
	auto it = table.find(rec.get_number(), rec);
	return *table.find(rec.get_number(), rec);
}

hash_table<record>::iterator phone_book::get_iterator(const record& rec)
{
	//return table.find(rec);
	return std::find(table.begin(), table.end(), rec);
}

void phone_book::erase(const record& rec)
{
	table.erase(std::pair<std::string, record>(rec.get_number(), rec));
}

void phone_book::touch(record&& rec)
{
	if (last_touched.size() == last_touched_max_size) last_touched.pop_front();
	last_touched.push_back(std::move(rec));
}

void phone_book::touch(const record& rec)
{
	if (last_touched.size() == last_touched_max_size) last_touched.pop_front();
	last_touched.push_back(rec);
}

void phone_book::touch_edit(record&& old, record&& update)
{
	if (last_edited.size() == last_edited_max_size) last_touched.pop_front();
	last_edited.emplace_back(std::move(old), std::move(update));
}

void phone_book::show_touched() const
{
	for (auto rec : last_touched)
	{
		std::cout << rec;
	}
}

void phone_book::print_command()
{
	std::cout << std::endl;
	for (int i = 0; i < 20; ++i) std::cout << '-';
	std::cout << std::endl;
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Add new record" << std::endl;
	std::cout << "2 - Edit record" << std::endl;
	std::cout << "3 - Search by substring" << std::endl;
	std::cout << "4 - Show all record" << std::endl;
	std::cout << "5 - Show last touched" << std::endl;
	std::cout << "6 - Undo editing" << std::endl;
	std::cout << "7 - Show all with numbers of block" << std::endl;
	for (int i = 0; i < 20; ++i) std::cout << '-';
	std::cout << std::endl;
}

void phone_book::save()
{
	std::fstream f;

	f.open("table.txt", 'w');

	if (!f.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		exit(-4);
	}

	for (auto it = table.begin(); it != table.end(); ++it)
	{
		f << *it;
	}

	f.close();
}

void phone_book::load()
{
	std::ifstream f;

	f.open("table.txt");

	if (!f.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		exit(-4);
	}

	record tmp;

	std::string name, surname, patronymic, number, email, company, job;
	while(!f.eof())
	{
		f >> tmp;
		add_record(tmp);
	}
	f.close();
}

std::pair<record, record> phone_book::get_last_edit()
{
	std::pair<record, record> p;
	if (!last_edited.empty())
	{
		p = *(--last_edited.end());
		last_edited.pop_back();
	}
	return p;
}

hash_table<record>::iterator phone_book::begin()
{
	return table.begin();
}

hash_table<record>::iterator phone_book::end()
{
	return table.end();
}
