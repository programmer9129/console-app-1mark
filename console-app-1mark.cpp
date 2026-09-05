#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "calculator_1.h"

using namespace std;
bool basher(string a)
{
	if (a.find("--valcon ", 0) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int commander_main(string f)
{
	// link commands with functions 
	if (f == "help")
	{
		std::cout << "hello this is valcon your flexible and usable console app" << std::endl;
		std::cout << "you can use the following codes to start vibin with valcon" << std::endl;
		std::cout << "'help' - show this msg" << std::endl;
		std::cout << "'exit' - exit the console" << std::endl;
	}
	else if (f == "exit")
	{
		std::cout << "exiting the console" << std::endl;
		exit(0);
	}
	else if (f == "calc")
	{
		std::cout << "enter your equation in the following format : 1+2=" << std::endl;
		std::string line;
		std::getline(std::cin, line);
		Calculator calc;
		calc.parser(line);
		std::cout << "the answer is : " << calc.sums << std::endl;
	}
	else
	{
		std::cout << "command not found" << std::endl;
	}
}
int main()
{
	
	std::cout << "                                         " << std::endl;
	std::cout << "                                         " << std::endl;
	std::cout << "                                         " << std::endl;
	std::cout << "                                         " << std::endl;
	std::cout << "                   try to vibe USER !              " << std::endl;
	std::cout << " THIS IS VALCON HERE ,YOUR PERSONAL NATURAL CONSOLE" << std::endl;
	std::cout << R"(
                                                                       ___
		              \\\      ///  ///\\\      |||         ///   \\\     ///|||\\\    |||\\\   |||
		               \\\    ///  ///  \\\     |||        ///          ///      \\\   ||| \\\  |||
		                \\\  ///  ///    \\\    |||       |||          |||        |||  |||  \\\ |||
		                 \\\///  ///||||||\\\   |||        \\\          \\\      ///   |||   \\\|||
		                  \\//  ///        \\\  ||||||||    \\\___///     \\\|||///    |||    \\|||)" << std::endl;


	while (true)
	{
		std::string line;
		std::getline(std::cin, line);
		if (basher(line) == true)
		{
			std::string command = line.substr(9);
			commander_main(command);
		}
		else {
			std::cout << "USER ACCESS DENIED" << std::endl;
		}




	}
}