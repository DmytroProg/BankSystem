#pragma once
#include "ServiceBase.h"
#include "not_supported_error.h"
#include "Card.h"

class CardService : public ServiceBase<Card>
{
public:
	void remove(Card item) override {

		items.erase(getCardByNumber(item.getNumber()));
	}

	void update(Card oldItem, Card newItem) override {
		throw new not_supported_error("Update method is not supported for card service");
	}

	vector<Card>::const_iterator getCardByNumber(long number) const {
		auto iter = items.begin();

		while (iter != items.end()) {
			if ((*iter).getNumber() == number) {
				break;
			}
			iter++;
		}

		if (iter == items.end())
			throw new exception("no card found");

		return iter;
	}
};

