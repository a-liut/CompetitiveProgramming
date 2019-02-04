#include <iostream>

using namespace std;

bool is_magic(string &number)
{
	if(number[0] != '1') return false;

	int8_t four_count = 0;
	for(size_t i = 1; i < number.size(); ++i)
	{
		if(number[i] == '1') four_count = 0; 
		else if(number[i] == '4' && four_count < 2) four_count++; 
		else return false;
	}

	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string number;

	cin >> number;

	cout << (is_magic(number) ? "YES" : "NO") << endl;
}
