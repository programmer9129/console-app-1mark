#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
		bool TOKEN = false;
		int count = 0;int count_mark = 0;
		for(int i=0;i<line.length();i++)
		{
			for (int j = 0;j < 4;j++)
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
				count = +1;
				numbers.push_back(line[i]);
			}
			else 
			{ 
				reverse(numbers.begin(), numbers.end());
				for (int n = numbers.size()-1;n >= 0;n--)
				{
					sums_unified = sums_unified + numbers[n]*(10^n);
				}
				sums_unification.push_back(sums_unified);
				operations.push_back(line[i]);
				numbers.clear();//number got intialised to 0
				count = 0;//counter is intialized to 0
			}
		}

	}

};