#include "hash_table.h"
#include "record.h"
#include "phone_book.h"
#include <fstream>

phone_book book;

void save()
{
	book.save();
}

int main()
{
	std::string s;
	atexit(save);
	
	book.load();
	char command = 1;

	record r;
	record find, edit = {};
	std::vector<record> v;
	std::pair<record, record> p;
	int i;
	hash_table<record>::iterator it = book.begin();

	while (command - '0')
	{

		if (command != -1) phone_book::print_command();
		command = getchar();
		if (command == '\n' || command == '\r')
		{
			command = -1;
			continue;
		}

		switch (command)
		{
		case '1': // add record
			std::cout << "Enter record. Example \"someSurname someName somePatronymic +7(123)456-78-90 email@email.email someCompany someJob\"";
			std::cout << std::endl;
			std::cin >> r;
			book.add_record(r);
			break;
		case '2': // edit record
			std::cout << "Enter record of human which record you want to edit" << std::endl;
			std::cin >> find;
			if (!book.contain(find))
			{
				std::cout << "Record not found" << std::endl;
				break;
			}
			std::cout << "Enter edited record" << std::endl;
			std::cin >> edit;
			if (edit.get_number() == find.get_number()) book.get_record(find) = edit;
			else
			{
				book.add_record(edit);
				book.get_record(find) = record();
			}
			book.touch_edit(std::move(find), std::move(edit));
			break;
		case '3': // search by sub str
			std::cout << "Enter substr" << std::endl;
			std::cin >> s;
			v = book.find_by_substr(s);
			for (auto& rec : v)
			{
				std::cout << rec;
				book.touch(std::move(rec));
			}
			break;
		case '4': // show all records
			for (auto iter = book.begin(); iter != book.end(); ++iter)
			{
				if (*iter != record())
				{
					std::cout << *iter;
					book.touch(*iter);
				}
			}
			break;
		case '5': // show last touched
			book.show_touched();
			break;
		case '6': // undo editing
			p = book.get_last_edit();
			if (!(p.first || p.second)) break;
			r = book.get_record(p.second);
			std::swap(r, p.first);
			break;
		case '7': // show with index
			i = 0;
			for (auto iter = book.begin(); iter != book.end(); ++iter, ++i)
			{
				if (*iter != record())
				{
					std::cout<< " [" << iter.get_index() << "] " << *iter;
				}
			}
			break;
		default: break;
		}
	}
	book.save();
	return 0;
}