#include "../../include/engine/MenuManager.h"
#include "../../include/service/CalculatorService.h"

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
		cin >> decision;
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
	waitForEnter();
}

void MenuManager::addPriceToTheItem() {
	clearScreen();
	cout << "---Dodawanie ceny do przedmiotu---\n";
	waitForEnter();
}

void MenuManager::loadPricesFromInternet() {
	clearScreen();
	cout << "---Ladowanie cen z internetu---\n";
	waitForEnter();
}

void MenuManager::useCalculator() {
	clearScreen();
	cout << "---Kalkulator---\n";
	waitForEnter();
}

void MenuManager::exitApp() {
	clearScreen();
	cout << "---Opuszczanie aplikacji---\n";
	isWorking = false;
}