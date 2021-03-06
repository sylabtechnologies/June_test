using namespace std;
typedef vector<int>	I_vec;

int distance(int a, int b)
{
	if ((a - b) >= 0) return a - b;

	if ((a - b) < 0 ) return b - a;

	cout << "Error" << endl; exit(1);
}

int min_distance(I_vec aa)
{
	int result;

	std::sort(_R1(aa));

	result = distance(aa[0], aa[1]);
	for (auto iter = aa.begin() + 1; iter != aa.end(); ++iter)
	{
		int new_dist = distance(*(iter-1), *iter);

		if (new_dist < result) result = new_dist;
	}

	return result;
}
