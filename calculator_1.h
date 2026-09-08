#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Calculator
{
private:
//	char operation[4] = { '+', '-', '*', '/' };
	//char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
public:
	long long sums = 0;
	long long sums_unified = 0;
	char operation[4] = { '+', '-', '*', '/' };

	
	long long parser(string line)
	{
		std::vector<int> numbers;
		std::vector<int>sums_unification;
		std::vector<char> operations;
		bool TOKEN = false;bool di_token = false;//the TOKEN cheker ticket 

		int j = 0;int i = 0;//identifiers for the for loops
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		int count = 0;//counter for array parsing 
		for (i = 0; i < line.length();i++)
		{
			for(j=0;j<4;j++)
			{
				if (line[i] == operation[j])
				{
					operations.push_back(operation[j]);
					TOKEN = true;
				}
				else if (line[i] == '=')
				{
					di_token = true;  //super token for answer analyzation process trigerring 
				}
				else
				{
					int partial_number = 0;
					partial_number = static_cast<int>(line[i]) - '0';  //str to int convertor
					numbers.push_back(partial_number);
					TOKEN = false;di_token = false;   //token fillation 
				}
			}
			if (TOKEN == true || di_token == true)
			{
				std::reverse(numbers.begin(), numbers.end());
				for (int k = 0;k < numbers.size();k++)
				{
					sums += numbers[k] * std::pow(10, k);
				}
				sums_unification.push_back(sums);
				numbers.clear();
				TOKEN = false;di_token = false;//token must be cleared off!
				if (i != line.length() - 1)
				{
					std::cout << "Error: '=' must be at the end of the expression" << std::endl;  //state the error for right input
					break;
				}
				else if (i == line.length() - 1)
				{
					break; // exit the loop if '=' is at the end of the expression
				}
			
			}
		}
		sums_unified = sums_unification[0];
		for (int k = 0;k < operations.size();k++)
		{
			if (operations[k] == '+')
			{
				sums_unified = sums_unified + sums_unifi 
			}
		}
	}

};
