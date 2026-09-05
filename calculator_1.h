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
	char operation[4] = { '+', '-', '*', '/' };
public:
	double nums;
	double sums;
	double sums_unified;

	void parser(string line)
	{
		std::vector<int> numbers;
		std::vector<int>sums_unification;
		std::vector<char> operations;
		bool TOKEN = false;//the TOKEN cheker ticket 
		
		int j = 0;int i = 0;//identifiers for the for loops

		int count = 0;//counter for array parsing 
		line.erase(remove(line.begin(), line.end(), '='), line.end());
		for (i = 0;i < line.length();i++)
		{
			for (j = 0;j < 4;j++)
			{
				if (line[i] == operation[j])
				{
					// Handle the operation
					bool TOKEN = true;
					operations.push_back(line[i]);
				}
				else
				{
					bool TOKEN = false;
				}
			}
			if (TOKEN == false)
			{
				count += 1;
				int num_standby = int(line[i]) - '0';//anscii to int converter
				numbers.push_back(num_standby);
			}
			else
			{
				reverse(numbers.begin(), numbers.end());
				for (int n = numbers.size() - 1;n >= 0;n--)
				{
					sums_unified = sums_unified + (numbers[n] * pow(10,n));
				}
				sums_unification.push_back(sums_unified);
				numbers.clear();//number got intialised to 0
				count = 0;//counter is intialized to 0
			}
		}
		for (i = 0;i < sums_unification.size();i++)
		{
			for (j = 0;j < operations.size();j++)
			{

				if (operations[j] == '+')
				{
					sums = sums_unification[i] + sums_unification[i + 1];
				}
				else if (operations[j] == '-')
				{
					sums = sums_unification[i] - sums_unification[i + 1];
				}
				/*else if (operations[j] == '*')
				{
					sums = sums_unification[i] * sums_unification[i + 1];
				}
				else if (operations[j] == '/')
				{
					sums = sums_unification[i] / sums_unification[i + 1];
				}*/
			}
		}
		return sums;
	}
};
