#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include "../model/Item.h"

using namespace std;

struct profit {
	City city;
	double profit;
};

class Calculator {
private:
	Item item;
	City startCity;
public:
	Calculator();
	profit calculateProfit(const Item&, const City&); //returns struct of the biggest profit and the city in which we sell for this profit
};