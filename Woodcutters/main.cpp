#include <iostream>
#include <vector>

using namespace std;

struct tree_t
{
	int64_t h, pos;
};

int64_t woodcutters(vector<tree_t> &trees)
{
	int64_t count = 0, i, left_border = trees[0].pos;

	for(i = 0; i < trees.size(); ++i)
	{
		// Check whether it can be thrown on the left
		if(i == 0 || trees[i].pos - trees[i].h > left_border)
		{
			left_border = trees[i].pos;
			count++;
		} 
		// Check whether it can be thrown on the right
		else if(i == trees.size() - 1 || trees[i].pos + trees[i].h < trees[i + 1].pos)
		{
			left_border = trees[i].pos + trees[i].h;
			count++;
		} else {
			left_border = trees[i].pos;
		}
	}

	return count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int64_t i, pos, h, n;
	vector<tree_t> trees;

	cin >> n;

	trees.resize(n);

	for (i = 0; i < n; ++i)
	{
		cin >> pos >> h;

		tree_t t;
		t.pos = pos;
		t.h = h;

		trees[i] = t;
	}

	cout << woodcutters(trees) << endl;
}
