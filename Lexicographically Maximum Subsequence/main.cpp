#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void lex_maximum_subsequence(string &s)
{
	int last = s.length() - 1, i;
	stack<int> st;

	st.push(last);

	for(i = s.length() - 2; i >= 0; --i)
	{
		if(s[i] >= s[last])
		{
			st.push(i);
			last = i;
		}
	}

	while(!st.empty())
	{
		cout << s[st.top()];
		st.pop();
	}

	cout << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	string s;

	cin >> s;

	lex_maximum_subsequence(s);
}
