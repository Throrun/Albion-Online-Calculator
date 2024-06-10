#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include "Item.h"

using namespace std;

struct profit {
	City city;
	double profit;
};

class Calculator {
public:
	Calculator(const Item&, const City&);
	profit calculateProfit(const Item&, const City&);
};