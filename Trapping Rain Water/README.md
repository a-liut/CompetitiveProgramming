# Trapping Rain Water

## Solution

The water trapped in the column i of the elevation map is calculated as follows:

	water = max (
				min(
					max( h[0], ..., h[i-1]),
					max( h[i+1], ..., h[n])
				) - h[i],
				0
		)

The algorith do three scan of the array.
The first scan finds the right maximum of every element. To do so, just scan the array from the end to the start and store the maximum element.

The second scan finds the left maximum of every element, like we found right maximums in the first scan but from start from end.

The third scan apply the formula to calculate the water using values calculated in the previous scans. 

## Complexity

The algorithm scans the array 3 times and every scan do O(1) operations.
Right and left maximums are stored in two arrays of the dimension of the elevation map given.

So, the algorithm is O(n) + O(n) + O(n) = O(n) time and O(n) space.