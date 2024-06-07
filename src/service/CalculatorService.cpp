#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "model/Item.h"

using namespace std;

class CalculatorService {
public:
    pair<City, double> calculateHighestProfit(const Item& item, const map<City, int>& basePrices) {
        double maxProfit = -1.0;
        City bestCity = City::BRIDGEWATCH;

        for (const auto& [city, price] : item.getPriceMap()) {
            if (basePrices.find(city) != basePrices.end()) {
                int basePrice = basePrices.at(city);
                if (basePrice > 0) {
                    double profit = (static_cast<double>(price) - basePrice) / basePrice * 100.0;
                    if (profit > maxProfit) {
                        maxProfit = profit;
                        bestCity = city;
                    }
                }
            }
        }

        return { bestCity, maxProfit };
    }
};