#pragma once
#include "ServiceBase.h"
#include "not_supported_error.h"
#include "Card.h"

class CardService : public ServiceBase<Card>
{
public:

	void remove(Card item) override {
		try {
			auto card = find_if(items.begin(), items.end(),
				[item](const Card& c) { return c.getNumber() == item.getNumber(); });
			if (card == items.end())
				throw exception("card is null");
			items.erase(card);
			logger.LogInfo("Card " + item.getNumber() + " was removed");
		}
		catch (exception& ex) {
			logger.LogError(ex);
		}
	}

	void update(Card oldItem, Card newItem) override {
		throw new not_supported_error("Update method is not supported for card service");
	}

	bool isValid(const Card& user) override {
		
		return true;
	}
};

