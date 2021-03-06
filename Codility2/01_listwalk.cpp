// Define list as Node #K points to the next node at aa[K]
// & terminates at TERMINATE_CODE

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<int> I_vec;

#define TERMINATE_CODE -1
#define MYMAX_INT 200000
#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter

int count_nodes(I_vec aa)
{
	int index = aa[0];
	int result = 1;

	while (index != TERMINATE_CODE)
	{
		index = aa[index];
		result++;
	}

	return result;
}

int main()
{
	vector<int> aa{1, 4, -1, 3, 2};

	cout << count_nodes(aa) << endl;

    return 0;
}

