# Maximum of all subarrays of size k

The solution of this problem is based on how the optimal sub-array is constructed.
The algorithm scans the array from the beginning to the end.

A deque is used to maintain an history of the elements scanned: the head of the deque maintain the current sub-array maximum and the tail contains all candidates maximums for next sub-arrays

A generic item at position i can be:
* a new maximum: In this case, any item between the previous item and the current item can be the maximum for the sub-array. So the current item is the new maximum for the sub-array.
* a candidate maximum: If is not the maximum, it can be the maximum value for the next subarray. If this item is a better candidate of the other in the tail, then remove the worst candidates in order from the tail, then add the new candidate to the tail.

# Complexity

The algorithm scans the array only once and adds and removes at most once an item into the deque, so the overall time complexity is O(n).