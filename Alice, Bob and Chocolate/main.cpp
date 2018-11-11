#include <iostream>
#include <vector>

using namespace std;

void chocolate(const vector<int> &bars)
{
	int alice = 0, bob = bars.size() - 1, aSum = 0, bSum = 0, aCount = 0, bCount = 0;

	while(alice <= bob) {
		if(aSum <= bSum) {
			aSum += bars[alice];
			aCount++;

			alice++;
		} else {
			bSum += bars[bob];
			bCount++;

			bob--;
		}
	}

	cout << aCount << " " << bCount << endl;
}

int main()
{
	int n, x;
	vector<int> bars;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		bars.push_back(x);
	}

	chocolate(bars);

	return 0;
}