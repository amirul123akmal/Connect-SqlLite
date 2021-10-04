#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

#include <sqlite3.h>

// Defining basic I/O utility
/// Print with nextline
#define CONSOLE(x) std::cout << x << std::endl
/// Print without nextline
#define LOG(x) std::cout << x

namespace basic
{
	// Clear Console Screen
	void clear();

	/// <summary>
	/// 1 = Red
	/// 2 = Green
	/// 3 = Yellow
	/// 4 = Blue
	/// 5 = Magenta
	/// 6 = Cyan
	/// </summary>
	/// <param name="text"></param>
	/// <param name="color"></param>
	void printColor(const std::string& text, const int& color);
}