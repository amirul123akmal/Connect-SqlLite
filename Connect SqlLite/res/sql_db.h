#include "functionality.h"

#include <sqlite3.h>

class sql
{
private:
	/// Place of database
	sqlite3* db = NULL;

	/// Any SQL command will ne to be passed here and cnverted to SQLite format
	sqlite3_stmt *execution = NULL;

	/// Command line execution
	std::string command{};

	/// 2D Array-Spaces
	/// We need to use vector because we dont know how big the table is
	std::vector<std::vector<std::string>> table{};

	void getData();
	std::string quoting(std::string data);

public:
	/// Initialized, open and save db in memory
	/// <param name="filename">home.db</param>
	sql(const char filename[]);

	int menu();

	void printData();

	void addData();

	/// <summary>
	/// Will return 0 if the operation gettin canceled
	/// </summary>
	/// <returns></returns>
	int delData();

	/// Close the DB automatically when the programs end 
	~sql();
};