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
		cout << "1. Wyswietl liste przedmiotow\n"
			<< "2. Dodaj/Edytuj wlasny przedmiot\n"
			<< "3. Pobierz ceny z Internetu\n"
			<< "4. Kalkulator\n"
			<< "5. Wyjscie z aplikacji\n";
		cout << "Wybierz opcje: ";
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
			AddItem();
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
			waitForEnter();
		}
	}
}

void MenuManager::showListOfItems() {
	clearScreen();
	cout << "[1] Lista przedmiotow\n";
	vector<Item> items = db.getAllItems();
	int l = 0;
	int cheapestPrice = 999999999;
	for (const auto& item : items) {
		map<City, int> prices = item.getPriceMap();
		map<City, int>::iterator it = prices.begin();
		if (l == 0) {
			cout << setw(20) << "Item";
			cout << setw(20) << "Tier";
			while (it != prices.end()) {
				cout << setw(20) << it->first;
				it++;
			}
			cout << endl;
		}
		it = prices.begin();
		cheapestPrice = 999999999;
		for (const auto& price : prices) {
			if (price.second < cheapestPrice && price.second > 0) {
				cheapestPrice = price.second;
			}
		}
		if (cheapestPrice != 999999999) {
			cout << setw(20) << item.getName() << setw(20) << item.getTier();
			do {
				cout << setw(20) << it->second;
				it++;
			} while (it != prices.end());
			cout << endl;
		}
		l++;
	}
	waitForEnter();
}

void MenuManager::AddItem() {
	clearScreen();
	int l = 0;
	string name;
	string str_tier;
	Tier tier = Tier::UNKNOWN;
	cout << "[2] Dodawanie wlasnego przedmiotu\n";

	cout << "Podaj nazwe przedmiotu, ktory chcesz stworzyc: ";
	cin.ignore();
	getline(cin, name);

	while (tier == Tier::UNKNOWN) {
		if (l > 0) {
			clearScreen();
			cout << "[2] Dodawanie wlasnego przedmiotu\n\n";
		}
		cout << "Podaj tier przedmiotu, ktory chcesz stworzyc: ";
		getline(cin, str_tier);
		tier = fromString(str_tier);
		l++;
	}

	Item item(NULL, name, tier);

	char isAdding = 't';
	int decision;
	int price;
	City chosen_city;

	while (isAdding == 't') {
		clearScreen();
		cout << "[2] Dodawanie wlasnego przedmiotu\n\n";
		for (int i = 0; i <= static_cast<int>(City::BRECILIEN); ++i) {
			City city = static_cast<City>(i);
			cout << i + 1 << ". " << city << endl;
		}

		cout << "\nWybierz miasto, dla ktorego chcesz ustalic cene " << item.getName() <<" 1 - 8: ";
		if (!(cin >> decision) || decision < 1 || decision > 8) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

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
		while (true) {
			clearScreen();
			cout << "[2] Dodawanie wlasnego przedmiotu\n\n";
			cout << "Podaj cene dla " << chosen_city << ": ";

			if (cin >> price) {
				break;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Niepoprawna cena!\n\n";
		}
		item.setPriceForCity(chosen_city, price);
		clearScreen();
		cout << "Czy chcesz dodac cene " << item.getName() << " w miescie ? [t / n]\n";
		cin >> isAdding;
		while (isAdding != 't' && isAdding != 'n') {
			clearScreen();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "[2] Dodawanie wlasnego przedmiotu\n\n";
			cout << "Niepoprawny wybor!\n\n";
			cout << "Czy chcesz dodac cene " << item.getName() << " w miescie ? [t / n]\n";
			cin >> isAdding;
		}
	}
	if (db.saveItem(item)) {
		clearScreen();

		cout << "Przedmiot dodany pomyslnie.\n\n";
	}
	waitForEnter();
}

void MenuManager::loadPricesFromInternet() {
	clearScreen();
	cout << "[3] Ladowanie cen z internetu\n";
	waitForEnter();
	//od api bool, który decyduje czy sie powiodlo
}

void MenuManager::useCalculator() {
	clearScreen();
	cout << "[4] Kalkulator \n";
	vector<Item> items = db.getAllItems();
	Calculator calc;
	cout << setw(20) << "Item" << setw(20) << "Tier" << setw(20) << "Buy city" << setw(20) << "Sell City" << setw(20) << "Income"<<endl;
	for (const auto& item : items) {
		int cheapestPrice= 276447231;
		City cheapestCity = City::BRIDGEWATCH;
		map<City, int> prices = item.getPriceMap();
		for (const auto& price : prices) {
			if (price.second < cheapestPrice && price.second > 0) {
				cheapestPrice = price.second;
				cheapestCity = price.first;
			}
		}
		if (cheapestPrice != 276447231) {
			profit result = calc.calculateProfit(item, cheapestCity);
			cout << setw(20) << item.getName() << setw(20) << item.getTier() << setw(20) << cheapestCity << setw(20) << result.city << setw(20) << result.profit << "%\n";
		}
		
	}
	waitForEnter();
}

void MenuManager::exitApp() {
	clearScreen();
	cout << "[5] Opuszczanie aplikacji\n";
	isWorking = false;
}