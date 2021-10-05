#include <iostream>
#include <sql_db.h>

int main(int argc, char **argv)
{
	sql manage("home.db");
	manage.delData();
	std::cin.get();
}