# Largest even number

Given a whole number x, the largest even number that we can build using the digits of x can be found by sorting the digits in descending order and moving the last event digit to the last position.

Ordering the array guarantee that the maximum value for the digit position is achieved. If we move another digit rather than the last even to the end of the sequence, we find an even number that cannot be the largest one.

# Complexity

The algorithm perform these steps:
* Sort the array of digits: theta(nlogn)
* Find the last even digit: O(n)
* Move the last even digit to the last position: O(n)

In total, the algorithm takes O(nlogn + n + n) = O(nlogn) and use O(1) additional space.