#pragma once
#include <vector>
template<typename T>
class ServiceBase
{
protected:
	std::vector<T> items;

public:
	virtual void add(T item) = 0;
	virtual void remove(T item) = 0;
	virtual void update(T oldItem, T newItem) = 0;
	std::vector<T> getAll() const{
		return items;
	}
};

