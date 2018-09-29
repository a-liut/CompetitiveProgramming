#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void towers(vector<int> bars)
{
    int count = 0, last_seen = -1, max_occurrencies = -1, occurrencies = 0;

    // first sort the array
    sort(bars.begin(), bars.end(), less<int>());

    for(vector<int>::iterator it = bars.begin(); it != bars.end(); it++)
    {
        if(*it > last_seen)
        {
            // increase towers count
            count++;

            // clear height for the new tower
            occurrencies = 1;

            // update the last seen element
            last_seen = *it;
        }
        else
        {
            // increase height of current tower
            occurrencies++;
        }

        // update maximum height
        if(occurrencies > max_occurrencies)
        {
            max_occurrencies = occurrencies;
        }
    }

    cout << max_occurrencies << " " << count << endl;
}

int main()
{
    int bar_number = 0;
    vector<int> bars;

    // read the number of bars available
    cin >> bar_number;

    bars.reserve(bar_number);

    // fill the array of bars length
    for(int i = 0; i < bar_number; i++)
    {
        int x = 0;
        cin >> x;
        bars.push_back(x);
    }

    towers(bars);

    return 0;
}

