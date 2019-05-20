#pragma once
#include "hash_table.h"
#include "record.h"

class phone_book
{
	static const int last_edited_max_size = 100;
	static const int last_touched_max_size = 100;
	std::list<std::pair<record, record>> last_edited;
	std::list<record> last_touched;
	hash_table<record> table;
public:
	void add_record(const record& rec);
	void add_record(std::string name, std::string surname, std::string patronymic, std::string number,
		std::string email, std::string company, std::string job);

	std::vector<record> find_by_substr(std::string s);

	bool contain(const record& rec);
	record& get_record(const record& rec);
	hash_table<record>::iterator get_iterator(const record& rec);

	void erase(const record& rec);
	void touch(record&& rec);
	void touch(const record& rec);
	void touch_edit(record&& old, record&& update);
	void show_touched() const;
	static void print_command();
	void save();
	void load();

	std::pair<record, record> get_last_edit();

	hash_table<record>::iterator begin();
	hash_table<record>::iterator end();

	phone_book() = default;
	~phone_book() = default;
};


