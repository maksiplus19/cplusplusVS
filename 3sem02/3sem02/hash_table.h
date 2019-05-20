#pragma once

#include "exception.h"
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <functional>
#include <algorithm>
#include <iostream>

template<typename T>
class hash_table
{
private:
	/**
	 * \brief Максимальная длина строки для хеширования
	 */
	static const int max_str_length = 105;
	/**
	 * \brief Размер хеш таблицы
	 */
	static const int record_count = 1024;
	/**
	 * \brief Хеш таблица
	 */
	std::vector<std::list<T>> table_;

	static unsigned long long simple_num_hash(const int degree)
	{
		static unsigned long long P[max_str_length];
		if (!P[degree])
		{
			P[degree] = 1;
			for (int i = 0; i < degree; ++i)
			{
				P[degree] *= 101;
			}
		}
		return P[degree];
	}

public:
	class iterator: public std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		typename std::list<T>::iterator iter_;
		hash_table* obj_;
		int current_index_;
	public:
		iterator(typename std::list<T>::iterator it, hash_table* p, int index);;
		iterator(const iterator& it) = default;

		iterator& operator++();
		iterator& operator++(int);
		iterator& operator--();
		iterator& operator--(int);
		iterator& operator=(const iterator& it);

		typename iterator::reference operator*()
		{
			return *iter_;
		}

		bool operator==(const iterator& it);
		bool operator!=(const iterator& it);

		int get_index() const;
	};
	
	iterator begin();
	iterator end();

	bool insert(std::string key, T value);
	bool erase(int index);
	iterator erase(std::pair<std::string, T> pair);
	iterator find(std::string s, const T& obj);

	static unsigned long long hash(std::string strObj);

	std::list<T>& operator[](std::string key);

	hash_table();
	hash_table(const hash_table&) = default;
	~hash_table() = default;
};

template <typename T>
hash_table<T>::iterator::iterator(typename std::list<T>::iterator it, hash_table* p, int index):
	iter_(std::move(it)), obj_(p), current_index_(index){}

template <typename T>
typename hash_table<T>::iterator& hash_table<T>::iterator::operator++()
{
	if (std::next(iter_) != obj_->table_[current_index_].end())
	{
		iter_ = std::next(iter_);
	}
	else
	{
		if (current_index_ == record_count)
		{
			std::cout << "Cannot increment end iterator" << std::endl;
			exit(-2);
		}
		++current_index_;
		iter_ = obj_->table_[current_index_].begin();
	}
	return *this;
}

template <typename T>
typename hash_table<T>::iterator& hash_table<T>::iterator::operator++(int)
{
	iterator tmp = *this;
	if (std::next(iter_) != obj_->table_[current_index_].end())
	{
		iter_ = std::next(iter_);
	}
	else
	{
		if (current_index_ == record_count)
		{
			std::cout << "Cannot increment end iterator" << std::endl;
			exit(-2);
		}
		++current_index_;
		iter_ = obj_->table_[current_index_].begin();
	}
	return tmp;
}

template <typename T>
typename hash_table<T>::iterator& hash_table<T>::iterator::operator--()
{
	if (iter_ != obj_->table_[current_index_].begin())
	{
		iter_ = std::prev(iter_);
	}
	else
	{
		if (current_index_ == 0)
		{
			std::cout << "Cannot decrement begin iterator" << std::endl;
			exit(-4);
		}
		--current_index_;
		iter_ = obj_->table_[current_index_].end();
		iter_ = std::prev(iter_);
	}
	return *this;
}

template <typename T>
typename hash_table<T>::iterator& hash_table<T>::iterator::operator--(int)
{
	iterator tmpIt = *this;
	if (iter_ != obj_->table_[current_index_].begin())
	{
		iter_ = std::prev(iter_);
	}
	else
	{
		if (current_index_ == 0)
		{
			std::cout << "Cannot decrement begin iterator" << std::endl;
			exit(-4);
		}
		--current_index_;
		iter_ = obj_->table_[current_index_].end();
		iter_ = std::prev(iter_);
	}
	return tmpIt;
}

template <typename T>
typename hash_table<T>::iterator& hash_table<T>::iterator::operator=(const iterator& it)
{
	iter_ = it.iter_;
	obj_ = it.obj_;
	current_index_ = it.current_index_;
	return *this;
}

template <typename T>
bool hash_table<T>::iterator::operator==(const iterator& it)
{
	return static_cast<bool>(this->iter_ == it.iter_);
}

template <typename T>
bool hash_table<T>::iterator::operator!=(const iterator& it)
{
	return static_cast<bool>(this->iter_._Ptr != it.iter_._Ptr);
}

template <typename T>
int hash_table<T>::iterator::get_index() const
{
	return current_index_;
}

template <typename T>
typename hash_table<T>::iterator hash_table<T>::begin()
{
	return iterator(table_[0].begin(), this, 0);
}

template <typename T>
typename hash_table<T>::iterator hash_table<T>::end()
{
	return iterator(table_[record_count].begin(), this, record_count);
}

template <typename T>
bool hash_table<T>::insert(std::string key, T value)
{
	std::list<T>& list = (*this)[key];
	if (*list.begin() == T()) 
		list.erase(list.begin());

	if(list.empty())
	{
		(*this)[key].push_back(value);
		return true;
	}

	auto found = std::find(list.begin(), list.end(), value);
	if (found == list.end())
	{
		(*this)[key].push_back(value);
		return true;
	}

	return false;
}

template <typename T>
bool hash_table<T>::erase(int index)
{
	try
	{
		table_[index].resize(0);
		table_[index].resize(1);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

template <typename T>
typename hash_table<T>::iterator hash_table<T>::erase(std::pair<std::string, T> pair)
{
	int index = hash_table::hash(pair.first) % record_count;
	auto it = std::find(table_[index].begin(), table_[index].end(), pair.second);
	if (it == table_[index].end()) return iterator(table_[index + 1].begin(), this, index + 1);
	auto next = it;
	if (std::next(it) == table_[index].end())
	{
		table_[index].erase(it);
		if (table_[index].empty())
		{
			table_[index].resize(1);
		}
		next = table_[++index].begin();
	}
	else
	{
		next = std::next(it);
		table_[index].erase(it);
	}
	return iterator(next, this, index);	
}

template <typename T>
typename hash_table<T>::iterator hash_table<T>::find(std::string s, const T& obj)
{
	auto it = std::find(table_[hash(s) % record_count].begin(), table_[hash(s) % record_count].end(), obj);
	if (it == table_[hash(s) % record_count].end()) return this->end();
	return iterator(it, this, hash(s) % record_count);
}

template <typename T>
unsigned long long hash_table<T>::hash(std::string strObj)
{
	if (strObj.size() > max_str_length)
	{
		std::cout << "Too long string for hash" << std::endl;
		exit(-1);
	}
	unsigned long long hash = -1;
	for (int i = 0; i < static_cast<int>(strObj.size()); ++i)
	{
		hash += static_cast<unsigned long long>(strObj[i]) * simple_num_hash(i);
	}
	return hash;
}

template <typename T>
std::list<T>& hash_table<T>::operator[](std::string key)
{
	return this->table_[hash(key) % record_count];
}

template <typename T>
hash_table<T>::hash_table()
{
	table_.resize(record_count + 1, std::list<T>(1));
}
