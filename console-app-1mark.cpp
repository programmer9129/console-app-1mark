#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

}
int main()
{
	while (true)
	{
		std::string line;
		std::getline(std::cin, line);
		if (basher(line) == true)
		{
			std::string command = line.substr(9);
			std::cout << "Command: " << command << std::endl;
		}
		else {
			std::cout << "user access denied " << std::endl;
		}




	}
}