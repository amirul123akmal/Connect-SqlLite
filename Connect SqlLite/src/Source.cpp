#include <iostream>
#include <sql_db.h>

int main(int argc, char **argv)
{
	sql manage("home.db");
loop_start:
	switch (manage.menu())
	{
	case 1:
		manage.printData();
		break;
	case 2:
		manage.addData();
		break;
	case 3:
		manage.delData();
		break;
	default:
		if (!manage.reqExit())
			goto loop_start;
		goto ending;
		break;
	}
	std::cin.ignore();
	std::cin.get();
	goto loop_start;
ending:
	std::cin.get();
}