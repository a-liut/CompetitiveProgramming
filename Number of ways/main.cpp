#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

int64_t number_of_ways(const vector<int64_t> &items)
{
	int64_t count = 0, S = 0, Sthird = 0, i = items.size() - 1, sum = 0;
	int64_t C[items.size()];

	for(int64_t it : items) {
		S += it;
	}

	// No partitioning in case S can't be divided by 3
	if(S % 3 != 0) {
		return 0;
	}

	Sthird = S / 3;

	// Build the suffixes count array
	C[i] = items.back() == Sthird;

	sum = items[i];
	i--;
	for(; i >= 0; i--)
	{
		sum += items[i];
		C[i] = C[i + 1] + (sum == Sthird);
	}

	// Compute prefix sums and check
	sum = 0;
	for(int64_t k = 0; k < items.size() - 2; k++)
	{
		sum += items[k];

		if(sum == Sthird) {
			count += C[k + 2];
		}
	}
	
	return count;
}

int main()
{
	int64_t n, x;
	vector<int64_t> items;

	cin >> n;

	for (int64_t i = 0; i < n; i++)
	{
		cin >> x;

		items.push_back(x);
	}

	cout << number_of_ways(items) << endl;

	return 0;
}