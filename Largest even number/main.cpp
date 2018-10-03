#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void largest_even_number(vector<int> &digits)
{
    // Sort the array
    sort(digits.begin(), digits.end(), greater<int>());

    // Move the last even digit to the less significant position
    int current = digits.size() - 1;
    while (current > -1 && digits[current] % 2 == 1)
    {
        current--;
    }

    int next;
    while (current > -1 && current < digits.size() - 1)
    {
        next = current + 1;

        int t = digits[next];
        digits[next] = digits[current];
        digits[current] = t;

        current++;
    }
}

int main()
{
    int T, x;
    vector<int> digits;

    scanf("%d", &T);
    // Read end-line
    getchar();

    for (int i = 0; i < T; i++)
    {
        while (isdigit(x = getchar()))
        {
            digits.push_back(x - '0');
        }

        if (!digits.empty()) {
            largest_even_number(digits);

        for (int d : digits)
        {
            cout << d;
        }
        cout << endl;
        }

        digits.clear();
    }

    return 0;
}