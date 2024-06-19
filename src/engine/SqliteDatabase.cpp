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

void SqliteDatabase::saveItem(City city, Item item) {
	
}

void SqliteDatabase::initDatabaseTables() {
	const char* sql = "CREATE TABL IF NOT EXISTS Items (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, tier TEXT, martlock INT, thetfort INT,fort_sterling INT, lymhurst INT, bridgewatch INT, caerleon INT, black_market INT, brecilien INT )";
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
		cout << "dupa";
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
	return itemList;
}

vector<Item> SqliteDatabase::getSpecificItems(vector<Item>)
{
	return vector<Item>();
}
