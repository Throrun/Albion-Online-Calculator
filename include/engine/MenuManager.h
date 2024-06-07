#pragma once

#include <iostream>

using namespace std;

class MenuManager {
public:
	MenuManager() {
		menuNavigator();
	}
	void menuNavigator(); //shows options in menu then asks to choose 1-5 and switch case
	void showListOfItems(); //shows table of items 
	void addPriceToTheItem(); //adds or edits a price to the item (300000/300 000/300k)
	void loadPricesFromInternet(); //loads prices from internet
	void useCalculator(); //uses object Calculator to calculate profit on all non-empty Items
	void exitApp(); //stops the application
};
