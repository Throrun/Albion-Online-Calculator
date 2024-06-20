#include "../../include/engine/SqliteDatabase.h"


void SqliteDatabase::runDatabase() {	
	try
	{
		int result = sqlite3_open("database.db", &db);
		if (result != SQLITE_OK) {
			throw std::exception("Baza danych się nie otworzyla");
		}
		std::cout << "Uruchomiono baze danych";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Nieoczekiwany błąd: " << e.what() << std::endl;
	}
}

bool SqliteDatabase::saveItem(Item item) {
<<<<<<< HEAD
	return true;
=======
	try{
		std::string name = item.getName();
		std::string tier = toString(item.getTier());
		map<City, int> prices = item.getPriceMap();
		std::string sql = "SELECT COUNT(*) FROM Items WHERE name = '" + name + "' AND tier = '" + tier + "';";
		sqlite3_stmt* stmt;
		int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
		if (rc != SQLITE_OK) {
			throw std::exception("wystapil blad z baza danych");
		}
		rc = sqlite3_step(stmt);
		
		if (sqlite3_column_int(stmt, 0) == 0) {
			std::string sql = "INSERT INTO Items (id,name,tier,martlock,thetfort,fort_sterling,lymhurst,bridgewatch,caerleon,black_market,brecilien) VALUES (NULL,'" + name + "','" + tier + "'," + std::to_string(prices[City::MARTLOCK]) + "," + std::to_string(prices[City::THETFORD]) + "," + std::to_string(prices[City::FORT_STERLING]) + "," + std::to_string(prices[City::LYMHURST]) + "," + std::to_string(prices[City::BRIDGEWATCH]) + "," + std::to_string(prices[City::CAERLEON]) + "," + std::to_string(prices[City::BLACK_MARKET]) + "," + std::to_string(prices[City::BRECILIEN]) + "); ";
			SqliteDatabase::executeSQL(sql.c_str());
		}
		else {
			std::string sql = "UPDATE Items SET martlock = " + std::to_string(prices[City::MARTLOCK]) + ",thetfort= " + std::to_string(prices[City::THETFORD]) + ",fort_sterling = " + std::to_string(prices[City::FORT_STERLING]) + ",lymhurst = " + std::to_string(prices[City::LYMHURST]) + ",bridgewatch =" + std::to_string(prices[City::BRIDGEWATCH]) + ",caerleon =" + std::to_string(prices[City::CAERLEON]) + ",black_market=" + std::to_string(prices[City::BLACK_MARKET]) + ",brecilien = " + std::to_string(prices[City::BRECILIEN]) + " WHERE name='" + name +"' AND tier='" + tier +"';";
			SqliteDatabase::executeSQL(sql.c_str());
		}
		return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << "blad przy dodawaniu uzytkownika : " << e.what() << std::endl;
		return false;
	}
>>>>>>> 89aca6507c00a98355e4150aeabca193e961a6e2
}

void SqliteDatabase::initDatabaseTables() {
	const char* sql = "CREATE TABLE IF NOT EXISTS Items (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, tier TEXT, martlock INT, thetfort INT,fort_sterling INT, lymhurst INT, bridgewatch INT, caerleon INT, black_market INT, brecilien INT )";
	SqliteDatabase::executeSQL(sql);
}

void SqliteDatabase::setDatabaseItems() {
	char* listOfItems[] = {
		"sword",
		"bow",
		"magic_staff"
	};
	for (char* item : listOfItems) {
		for (int tier = 4; tier <= 8; tier++)
		{
			for (int enchant = 0; enchant <= 4; enchant++)
			{
				char sql[256];
				snprintf(sql, sizeof(sql), "INSERT INTO Items (name, tier) VALUES('%s', '%d.%d');", item, tier, enchant);
				SqliteDatabase::executeSQL(sql);
			}
		}
	}
}

vector<Item> SqliteDatabase::getAllItems()
{
	vector<Item> itemList;
	const char* selectDataSQL = "SELECT * FROM Items;";
	sqlite3_stmt* stmt;
	
	
	rc = sqlite3_prepare_v2(db, selectDataSQL, -1, &stmt, nullptr);

	if (rc == SQLITE_OK) {
		while (sqlite3_step(stmt) == SQLITE_ROW) {
			std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			std::string tier = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			Item item = Item(NULL, name, fromString(tier));
			for (int i = 3; i <= static_cast<int>(City::BRECILIEN) + 3; ++i) {
				int price = sqlite3_column_int(stmt, i);
				City city = static_cast<City>(i - 3);
				item.setPriceForCity(city, price);
			}
			std::cout << name << " " << tier << std::endl;
			itemList.push_back(item);
		}
		sqlite3_finalize(stmt);
	}
	else {
		std::cout<< "dupa: " << sqlite3_errmsg(db);
	}
	return itemList;
}

vector<Item> SqliteDatabase::getSpecificItems(vector<Item>)
{
	return vector<Item>();
}
