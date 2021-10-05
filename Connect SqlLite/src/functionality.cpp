#include "functionality.h"

namespace basic
{
	static void change(const int& coded)
	{
		switch (coded)
		{
		case 1:
			printf("\033[0;31m");
			break;
		case 2:
			printf("\033[0;32m");
			break;
		case 3:
			printf("\033[0;33m");
			break;
		case 4:
			printf("\033[0;34m");
			break;	
		case 5:		
			printf("\033[0;35m");
			break;	
		case 6:		
			printf("\033[0;36m");
			break;
		default:
			break;
		}
	}
	void clear()
	{
		system("cls");
	}
	void printColor(const std::string& text,const int& color)
	{
		// White = 37m
		// Reset = 0m
		change(color);

		printf("%s", text.c_str());

		// Reset the color
		printf("\033[0;37m");
		
	}
	void printTable(const std::vector<std::vector<std::string>>& table)
	{
		for (int i = 0; i < table.size() ;i++)
		{
			for (int j = 0; j < table[i].size(); j++)
			{
				LOG(" " + table[i][j]);
			}
			LOG("\n");
		}
	}
}