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
	table.clear();

	int counter = 0;
	std::vector<std::string> column{};

	command = "SELECT * FROM home ";
	sqlite3_prepare(db, command.c_str(), -1, &execution, NULL);
	sqlite3_step(execution);

	int col = sqlite3_column_count(execution);
	while (sqlite3_column_text(execution, counter++))
	{
		column.clear();
		for (int i = 0; i < col; i++)
		{
			column.push_back(std::string((char*)sqlite3_column_text(execution, i)));
		}
		table.push_back(column);
		sqlite3_step(execution);
	}
	basic::printTable(table);
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