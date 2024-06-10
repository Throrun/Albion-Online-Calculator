#include "CalculatorService.h"


Calculator::Calculator(const Item& item, const City& startCity) {
	calculateProfit(item, startCity);
}

profit Calculator::calculateProfit(const Item& item, const City& startCity) {
	profit prof;
	int a = 5;
	map<City, int> prices = item.getPriceMap();
	map<City, int>::iterator it = prices.begin();

	prof.profit = 0;
	prof.city = startCity;

	while (it != prices.end()) {
		double price = static_cast<double>(it->second);
		double startPrice = static_cast<double>(prices.at(prof.city));
		if (price > 0) {
			if (((price - startPrice) / startPrice) * 100.0 > prof.profit) {
				prof.profit = ((price - startPrice) / startPrice) * 100.0;
				prof.city = it->first;
			}

		}
		it++;
	}
	cout << prof.city << " " << prof.profit;
	std::this_thread::sleep_for(std::chrono::seconds(10));
	return prof;
}