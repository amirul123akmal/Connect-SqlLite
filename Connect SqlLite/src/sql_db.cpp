#include "sql_db.h"

sql::sql(const char filename[])
{
	sqlite3_open(filename, &db);
	getData();
}

int sql::menu()
{
	basic::clear();
	int user;
	basic::printColor("Enter other than 1, 2, 3 to exit\nEvery pause, please press 'Enter'at your keyboard\n\n", 6);
	basic::printColor("1. Family Members\n", 2);
	basic::printColor("2. Add New Data\n", 3);
	basic::printColor("3. Delete Data\n", 1);
	std::cin >> user;
	return user;
}

void sql::printData()
{
	getData();
	basic::clear();
	basic::printTable(table);
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
}

std::string sql::quoting(std::string data)
{
	return std::string("'") + data + std::string("'");
}

void sql::addData()
{
	int id = 0;
	std::string umur{};
	std::string name{};
	std::string noTel{};

	getData(); // To check if there any update on the database
	for (int i = 0;i < table.size(); i++)
	{
		id = std::stoi(table[i][0]);
	}

	basic::clear();
	std::cin.ignore();
	LOG("Name: ");
	std::getline(std::cin, name);
	LOG("Umur: ");
	std::getline(std::cin, umur);
	LOG("NoTel: ");
	std::getline(std::cin, noTel);
	command = "INSERT INTO home VALUES("
		+ quoting(std::to_string(++id)) + "," 
		+ quoting(name) + "," 
		+ quoting(umur) + "," 
		+ quoting(noTel) + ");";

	sqlite3_prepare(db,command.c_str(), -1, &execution, NULL );
	sqlite3_step(execution);
}

int  sql::delData()
{
	std::string choose{};
	getData();
	basic::clear();
	basic::printTable(table);
	printf("\nType 'cancel' to cancel the operation");
	printf("\nWhich ID do you want to delete (at the front of every line): ");
	std::cin >> choose;
	if (choose == "cancel")
		return 0;
	command = "DELETE FROM home WHERE id = " + quoting(choose) + ";";
	sqlite3_prepare(db, command.c_str(), -1, &execution, NULL);
	sqlite3_step(execution);
}

bool sql::reqExit()
{
	basic::clear();
	std::string answer{};
	std::cin.ignore();
	LOG("Do you want to exit (y/n):");
	std::getline(std::cin, answer);
	if (answer == "y")
		return true;
	return false;
}

sql::~sql()
{
	sqlite3_finalize(execution);
	sqlite3_close(db);
}