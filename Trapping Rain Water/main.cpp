#include <iostream>
#include <algorithm>
using namespace std;

// This function calculate how much water is trapped in the elevation map.
int calculateWater(int map[], int n)
{
	cout << "[";
	for(int i = 0; i < n; i++) {
		cout << map[i] << ",";
	}
	cout << "]" << endl;


	int absMax = 0, localMax = 0, localMin = 0, water = 0, sum = 0, base = 0;

	for(int i = 0; i < n; i++)
	{

		if(map[i] >= map[absMax]) {
			// new abs max or flat found
			absMax = i;
			s = 0;
		} else {
			
		}

		// a new ansolute max or a flat is discovered
		if(map[i] >= map[absMax]) {

			// calculate water
			base = localMin - absMax;
			area = base * std::min(map[i], map[absMax]);
			water = water + area - sum;

			s = area


			absMax = i;
			s = 0;
		} else {

		}
	}






	// infinite is 10, according to constraint 0 <= arr[i] < 10
    int max = 0, ground = 0, water = 0, s = 0;
    for(int i = 1; i < n; i++)
    {
    	cout << "evaluating map[" << i << "] = " << map[i] << endl;
    	if(ground > -1 && map[max] > map[i] && map[ground] < map[i]) {
    		int base, area, localMin;
    		base = ground - max;
    		localMin = std::min(map[max] - map[groud], map[i] - map[groud]);
    		area = base * localMin;

    		cout << "base = " << base << endl;
    		cout << "ground = " << ground << endl;
    		cout << "localMin = " << localMin << endl;
    		cout << "area = " << area << endl;
    		cout << "s = " << s << endl;

    		water = water + area - s;
    		ground = i;

    		cout << "water = " << water << endl;

    		s = (base + 1) * localMin;

    		cout << "1>>s = " << s << endl;
    	}


    	if(ground == -1 || map[i] <= map[ground]) {
    		s = s + map[i];
    		ground = i;
    		cout << "3>>s = " << s << endl;
    	}
    	if(max == -1 || map[i] >= map[max]) {
    		max = i;
    		s = 0;
    		cout << "2>>s = " << s << endl;
    	}
    }

    cout << "water = " << water << endl;
    // return quantity of water
    return water;
}

int main()
{

    int cases, a[100], n;

    // read test cases
    cout << "insert cases number" << endl;
    cin >> cases;

    while(cases > 0)
    {

        // read array size
        cout << "insert n for test " << cases << endl;
        cin >> n;

        // fill the array
        for(int i = 0; i < n; i++)
        {
            cout << "insert value " << i << endl;
            cin >> a[i];
        }

        // calculate result and print to stdout
        cout << calculateWater(a, n) << endl;

        // decrement case number
        cases--;
    }


    return 0;
}