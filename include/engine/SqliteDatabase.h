#pragma once
#include "../model/City.h"
#include "../model/Item.h"
#include "../../sqlite/sqlite3.h"
#include <vector>
class SqliteDatabase {
private:
	//TODO SqliteDatabase* singleton;
	sqlite3* db;
	int rc;
	void executeSQL(const char* sql) {
		char* errorMessage = nullptr;
		try
		{
			int result = sqlite3_exec(db, sql, nullptr, nullptr, &errorMessage);
			if (result != SQLITE_OK) {
				throw("SQL ERROR: " + *errorMessage);
			}
			std::cout << "dodano: " << sql <<  std::endl;
		}
		catch (const std::exception&)
		{

		}
		
	}
public:
	// Default constructor (Singleton)
	//TODO SqliteDatabase SqliteDatabase();
	// Method used for run connection to database
	void runDatabase();
	// Method used for saving Items in database
	void saveItem(City city, Item item);
	// Method used for creation database based on csv file
	void initDatabaseTables();
	// Method used for set all items in db
	void setDatabaseItems();
	// Method used for get all filled items from db
	vector<Item> getAllItems();
	// Method used for get specific filled items from db
	vector<Item> getSpecificItems(vector<Item>);
};