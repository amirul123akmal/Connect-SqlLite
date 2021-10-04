#include "sql_db.h"

sql::sql(const char filename[])
{
	sqlite3_open(filename, &db);
}

int sql::menu()
{
	int user;
	basic::printColor("1. Family Members\n", 2);
	basic::printColor("2. Add New Data\n", 3);
	basic::printColor("3. Delete Data\n", 1);
	std::cin >> user;
	return user;
}

void sql::getData()
{
	command = "SELECT * FROM home ";
	sqlite3_prepare(db, command.c_str(), -1, &execution, NULL);
	sqlite3_step(execution);

	int S_col = sqlite3_column_count(execution);
}

void sql::addData()
{
	// Dynamically scan db column and retrieve data
	// Than request user
}

void sql::delData()
{

}

sql::~sql()
{
	sqlite3_finalize(execution);
	sqlite3_close(db);
}