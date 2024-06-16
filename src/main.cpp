#include <iostream>
#include "../include/engine/main.h"

using namespace std;

int main() {

    Item item(1, "Sword", Tier::TIER_4_0);
    item.setPriceForCity(City::BRIDGEWATCH, 100);
    item.setPriceForCity(City::LYMHURST, 120);
    item.setPriceForCity(City::FORT_STERLING, 90);
    item.setPriceForCity(City::THETFORD, 110);
    item.setPriceForCity(City::MARTLOCK, 95);

    Calculator calc(item, City::BRIDGEWATCH);

    calc.calculateProfit(item, City::BRIDGEWATCH);

    MenuManager m;

	return 0;
}