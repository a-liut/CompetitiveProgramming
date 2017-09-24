# Maximum of all subarrays of size k

The solution of this problem is based on how the optimal sub-array is constructed.

Scanning the array, the element at position i can be:
* included in the current sub-array
* included in a new sub-array starting from position i

The maximum of this two cases is the new current sub-array sum and it can be compared with the absolute maximum stored previously.

So, the algorithm runs in O(n) time thus it scan all elements once a time.
