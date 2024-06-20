#include "../../include/engine/SqliteDatabase.h"


void SqliteDatabase::runDatabase() {	
	try
	{
		int result = sqlite3_open("database.db", &db);
		if (result != SQLITE_OK) {
			throw std::runtime_error("Baza danych się nie otworzyla");
		}
		std::cout << "Uruchomiono baze danych";
	}
	catch (const std::exception&)
	{}
}

bool SqliteDatabase::saveItem(Item item) {
	return true;
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
	return vector<Item>();
}

vector<Item> SqliteDatabase::getSpecificItems(vector<Item>)
{
	return vector<Item>();
}
