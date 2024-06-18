#include "../../include/engine/MenuManager.h"


inline void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void MenuManager::waitForEnter() {
	cout << "\nNacisnij Enter, aby kontynuowac...";
	cin.ignore();
	cin.get();
}

void MenuManager::menuNavigator() {
	int decision;
	while (isWorking) {
		clearScreen();
		cout << "1. Wyswietl liste przedmiotow\n2. Dodaj cene przedmiotu\n3. Pobierz ceny z Internetu\n4. Kalkulator\n5. Wyjscie z aplikacji\n";
		if (!(cin >> decision)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		switch (decision) {
		case 1:
			showListOfItems();
			break;
		case 2:
			addPriceToTheItem();
			break;
		case 3:
			loadPricesFromInternet();
			break;
		case 4:
			useCalculator();
			break;
		case 5:
			exitApp();
			break;
		default:
			cout << "Niepoprawna decyzja!\n";
		}
	}
}

void MenuManager::showListOfItems() {
	clearScreen();
	cout << "---Lista przedmiotow---\n";
	vector<Item> items = db.getAllItems();
	int l = 0;
	for (const auto& item : items) {
		map<City, int> prices = item.getPriceMap();
		map<City, int>::iterator it = prices.begin();
		if (l == 0) {
			cout << setw(20) << "Item";
			while (it != prices.end()) {
				cout << setw(20) << it->first;
				it++;
			}
			cout << endl;
		}
		it = prices.begin();
		cout << setw(20) << item.getName();
		do{
			cout << setw(20) << it->second;
			it++;
		} while (it != prices.end());
		cout << endl;
		l++;
	}
	waitForEnter();
}

void MenuManager::addPriceToTheItem() {
	clearScreen();
	string name;
	string str_tier;
	Tier tier;
	cout << "---Dodawanie ceny do przedmiotu---\n";

	cout << "Podaj nazwe przedmiotu, ktory chcesz stworzyc: ";
	cin >> name;

	cout << "Podaj tier przedmiotu, ktory chcesz stworzyc: ";
	cin >> str_tier;
	tier = fromString(str_tier);

	Item item(NULL, name, tier);

	char isAdding = 't';
	int decision;
	int price;
	City chosen_city;
	cout << "Czy chcesz dodac cene " << item.getName() << " w miescie ? [t / n]\n";
	cin >> isAdding;
	while (isAdding == 't') {
		clearScreen();
		cout << "---Dodawanie ceny do przedmiotu---\n\n";
		for (int i = 0; i <= static_cast<int>(City::BRECILIEN); ++i) {
			City city = static_cast<City>(i);
			cout << i+1 << ". " << city << endl;
		}
		cout << "Wybierz miasto 1-8: ";
		cin >> decision;
		switch (decision) {
		case 1:
			chosen_city = City::BRIDGEWATCH;
			break;
		case 2:
			chosen_city = City::LYMHURST;
			break;
		case 3:
			chosen_city = City::FORT_STERLING;
			break;
		case 4:
			chosen_city = City::THETFORD;
			break;
		case 5:
			chosen_city = City::MARTLOCK;
			break;
		case 6:
			chosen_city = City::CAERLEON;
			break;
		case 7:
			chosen_city = City::BLACK_MARKET;
			break;
		case 8:
			chosen_city = City::BRECILIEN;
			break;
		default:
			cout << "Niepoprawna decyzja!\n";
		}
		cout << "Podaj cene dla " << chosen_city << ": ";
		cin >> price;
		item.setPriceForCity(chosen_city, price);
		clearScreen();
		cout << "Czy chcesz dodac cene " << item.getName() << " w miescie ? [t / n]\n";
		cin >> isAdding;
	}
	if (db.saveItem(item)) {
		cout << "Przedmiot dodany pomyslnie.\n\n";
	}
	waitForEnter();
}

void MenuManager::loadPricesFromInternet() {
	clearScreen();
	cout << "---Ladowanie cen z internetu---\n";
	waitForEnter();
	//od api bool, który decyduje czy sie powiodlo
}

void MenuManager::useCalculator() {
	clearScreen();
	cout << "---Kalkulator---\n";
	vector<Item> items = db.getAllItems();
	Calculator calc;
	cout << setw(20) << "Item" << setw(20) << "Tier" << setw(20) << "Buy city" << setw(20) << "Sell City" << setw(20) << "Income"<<endl;
	for (const auto& item : items) {
		int cheapestPrice=99999999999999;
		City cheapestCity = City::BRIDGEWATCH;
		map<City, int> prices = item.getPriceMap();
		for (const auto& price : prices) {
			if (price.second < cheapestPrice) {
				cheapestPrice = price.second;
				cheapestCity = price.first;
			}
		}
		profit result = calc.calculateProfit(item, cheapestCity);
		cout << setw(20) << item.getName() << setw(20) << item.getTier() << setw(20) << cheapestCity << setw(20) << result.city << setw(20) << result.profit << "%\n";
	}
	waitForEnter();
}

void MenuManager::exitApp() {
	clearScreen();
	cout << "---Opuszczanie aplikacji---\n";
	isWorking = false;
}