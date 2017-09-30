#include <iostream>
#include <vector>
#include <algorithm>

// this method print the height of the largest tower and the number of towers.
void towers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    int count = 0, last_seen = -1, max_occurrencies = -1, occurrencies = 0;

    // first sort the array
    std::sort(first, last, std::less<int>());

    for(std::vector<int>::iterator it = first; it != last; it++)
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

    std::cout << max_occurrencies << " " << count << std::endl;
}

int main()
{
    // disable synchronization for streams
    std::ios_base::sync_with_stdio(false);

    int bar_number = 0;
    std::vector<int> bars;

    // read the number of bars available
    std::cin >> bar_number;

    bars.reserve(bar_number);

    // fill the array of bars length
    for(int i = 0; i < bar_number; i++)
    {
        int x = 0;
        std::cin >> x;
        bars.push_back(x);
    }

    towers(std::begin(bars), std::end(bars));

    return 0;
}

