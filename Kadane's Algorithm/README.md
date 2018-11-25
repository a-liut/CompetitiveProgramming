# Kadane's Algorithm

## Solution

The algorithm scans the array maintaining at each step the maximum subset sum found.

For each element, it checks if the current element can be inserted into the candidate solution or it is a new candidate solution by itself.

## Complexity

The time complexity is O(n) since the algorithm has to scan the array only once.