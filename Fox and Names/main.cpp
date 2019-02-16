#include <iostream>
#include <vector>
#include <stack>

#define MAX_NAMES 100
#define LETTERS_NO u'z' - u'a' + 1
#define LETTER_IDX(x) x - u'a'

using namespace std;

// DFS colors
uint8_t color[LETTERS_NO];

stack<size_t> dfs_stack;
int64_t counter = LETTERS_NO;

void dfs_visit(bool graph[LETTERS_NO][LETTERS_NO], size_t pos, int64_t &time) {
	time++;
	color[pos] = 1; // Gray
	counter--;

	for(size_t i = 0; i < LETTERS_NO; ++i)
	{
		if(graph[pos][i] && color[i] == 0) dfs_visit(graph, i, time);
	}

	color[pos] = 2;
	time++;

	dfs_stack.push(pos);
}

void dfs(bool graph[LETTERS_NO][LETTERS_NO], size_t in_degrees[])
{
	int64_t time = 0;
	size_t i = 0;
	stack<size_t> s;
	for(i = 0; i < LETTERS_NO; ++i)
	{
		color[i] = 0; // white
	}

	for(i = 0; i < LETTERS_NO; ++i) if(in_degrees[i] == 0) s.push(i);

	size_t current = 0;
	while(!s.empty())
	{
		current = s.top();
		s.pop();

		if(color[current] == 0 && in_degrees[current] == 0) dfs_visit(graph, current, time);
	}
}

size_t first_diff(string &a, string &b)
{
	size_t i = 0;
	while(i < a.size() && i < b.size())
	{
		if(a[i] != b[i]) {
			return i;
		}
		i++;
	}

	return -1;
}

void ordering(vector<string> const &names, size_t n)
{
	size_t i, j;
	bool graph[LETTERS_NO][LETTERS_NO];
	size_t in_degrees[LETTERS_NO];

	// Init table with alphabetic order
	for(i = 0; i < LETTERS_NO; ++i)
	{
		for(j = 0; j < LETTERS_NO; ++j) {
			graph[i][j] = false;
		}

		in_degrees[i] = 0;
	}

	for(i = 1; i < n; ++i)
	{
		string a = names[i - 1], b = names[i];

		size_t fd = first_diff(a, b);
		if(fd != -1) {
			char c1 = a[fd];
			char c2 = b[fd];

			graph[LETTER_IDX(c1)][LETTER_IDX(c2)] = 1;
			in_degrees[LETTER_IDX(c2)]++;
		} else
		{
			if(b.length() < a.length())
			{
				cout << "Impossible" << endl;

				return; // Self loop.
			}
		}
	}

	dfs(graph, in_degrees);

	if(counter > 0)
		cout << "Impossible" << endl;
	else 
	{
		size_t current;
		while(!dfs_stack.empty())
		{
			current = dfs_stack.top();
			cout << (char)(current + 'a');
			dfs_stack.pop();
		}
		cout << endl;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	size_t n, i;
	string x;
	vector<string> names;

	cin >> n;

	names.resize(n);
	for(i = 0; i < n; ++i)
	{
		cin >> x;

		names[i] = x;
	}

	ordering(names, n);
}
