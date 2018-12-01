#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define MEGACITY 1000000

struct city_t
{
	int x;
	int y;
	int k;
	double radius;
};

double tomks_min_radius(int people, city_t cities[], int n)
{
	int count = people, i = 0;
	double ret;

	// compute radiuses
	for (i = 0; i < n; i++)
	{
		double rad = sqrt(pow(cities[i].x, 2) + pow(cities[i].y, 2));
		cities[i].radius = rad;
	}

	// sort by radius
	sort(cities, cities + n, [=](city_t c1, city_t c2) { return c1.radius < c2.radius; });

	// compute the minimum radius
	i = 0;
	while (i < n && count < MEGACITY)
	{
		ret = cities[i].radius;
		count += cities[i].k;
		i++;

		while(cities[i - 1].radius == cities[i].radius)
		{
			count += cities[i].k;
			i++;
		}
	}

	if(count < MEGACITY)
	{
		ret = -1;
	}

	return ret;
}

int main()
{
	int n, people, x, y, k;

	cin >> n;
	cin >> people;

	city_t cities[n];

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		cin >> k;

		city_t c;
		c.x = x;
		c.y = y;
		c.k = k;
		c.radius = 0;

		cities[i] = c;
	}

	double r = tomks_min_radius(people, cities, n);
	cout.precision(8);
	cout << r << endl;
}