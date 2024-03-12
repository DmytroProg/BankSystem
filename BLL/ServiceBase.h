#pragma once
#include <vector>
template<typename T>
class ServiceBase
{
protected:
	std::vector<T> items;

public:
	virtual void add(T item) {
		if (!isValid(item))
			throw new std::exception("not valid");

		items.push_back(item);
	}

	virtual void remove(T item) = 0;
	virtual void update(T oldItem, T newItem) = 0;
	std::vector<T> getAll() const{
		return items;
	}

	virtual bool isValid(const T& item) = 0;

	typename auto find(bool (*pred)(const T& item)) {
		for (auto iter = items.begin(); iter != items.end(); iter++) {
			if (pred(*iter)) {
				return iter;
			}
		}
		return items.end();
	}
};

