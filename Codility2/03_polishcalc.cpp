// Implement simple polish notation calculator for unsigned integers [0:2^20-1]

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

const char Bell = 7;

#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter

#define MY_MAX_INT	1048575
#define MY_ERR_CODE -1
#define ERROR(X)	{std::cout << Bell << X << std::endl; return MY_ERR_CODE; }

// implement polish notation
// return MY_ERR_CODE if overflow
int polish_calc(const string& operations)
{
	string elem;
	list<int> mystack;

	int result = 0;

	stringstream mystream(operations);

	while (mystream >> elem)
	{
		if (elem == "+")
		{
			if (mystack.size() < 2) ERROR("stack underflow");

			int oper1 = mystack.back(); mystack.pop_back();
			int oper2 = mystack.back(); mystack.pop_back();
			int sum = oper1 + oper2;

			if (sum > MY_MAX_INT) ERROR("overflow");
			mystack.push_back(sum);
		}
		else if (elem == "-")
		{
			if (mystack.size() < 2) ERROR("stack underflow");

			int oper1 = mystack.back(); mystack.pop_back();
			int oper2 = mystack.back(); mystack.pop_back();
			int subtract = oper1 - oper2;

			if (subtract < 0) ERROR("underflow");
			mystack.push_back(subtract);
		}
		else if (elem == "DUP")
		{
			int mydup = mystack.back();
			mystack.push_back(mydup);
		}
		else if (elem == "POP")
		{
			mystack.pop_back();
		}
		else if (find_if(_R1(elem), [](char c)->bool {return(!isdigit(c));}) == elem.end())
		{
			mystack.push_back(stoi(elem));
		}
		else
		{
			ERROR("invalid operand " + elem);
		}
	}

	if (mystack.size() < 1) ERROR("invalid sequence");

	return mystack.back();
}


int main()
{
	string test{ "3 DUP 5 - +"};

	cout << test << endl;
	cout << "="  << endl;

	int result = polish_calc(test);
	if (result != MY_ERR_CODE) cout << result << endl;
	
    return 0;
}

