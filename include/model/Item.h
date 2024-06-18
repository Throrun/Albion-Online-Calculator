#pragma once

#include <iostream>
#include <string>
#include <map>
#include "Tier.h"
#include "City.h"

using namespace std;

class Item {
private:
	int id;
	string name;
	Tier tier;
	map<City, int> priceMap;
public:
	Item(int id, const string& name, Tier tier) {
		this->id = id;
		this->name = name;
		this->tier = tier;
	}

	void setPriceForCity(City city, int price) {
		priceMap[city] = price;
	}

	const map<City, int>& getPriceMap() const {
		return priceMap;
	}

	const string getName() const {
		return name;
	}

	const Tier getTier() const {
		return tier;
	}
};