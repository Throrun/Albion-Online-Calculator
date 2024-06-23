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
	//allows to set price for an city
	void setPriceForCity(City city, int price) {
		priceMap[city] = price;
	}
	//returns list of prices asigned to cities
	const map<City, int>& getPriceMap() const {
		return priceMap;
	}
	//returns name of an item
	const string getName() const {
		return name;
	}
	//returns tier of an item
	const Tier getTier() const {
		return tier;
	}
};