#include <iostream>
#include "../../include/engine/SqliteDatabase.h"

int main() {
    SqliteDatabase db;
    db.runDatabase();
    db.getAllItems();