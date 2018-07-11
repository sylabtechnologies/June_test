#include <vector>
using namespace std;
typedef vector<int> I_vec;

bool almost_sorted(I_vec& arr)
{
	int num_diff = 0;

	I_vec test(_R1(arr));
	std::sort(test.begin(), test.end());

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != test[i]) num_diff++;
	}

	return (num_diff == 0 || num_diff == 2) ? true : false;
}
