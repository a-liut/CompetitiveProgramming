# Next larger element

## Solution

### Naive

The naive solution find, for each element, the next larger element. At worst case, the array is reverse ordered and the algorithm scans the array entirely before printing -1. Thus, the time complexity is O(n^2).

### Linear time

To get the next larger element of a generic element i, is necessary to store the next larger elements of the previous elements.

The linear time solution scans the array backwards maintaining in a deque the next larger elements found. To do this, evaluating a generic element i, it removes smaller elements from the queue because the cannot be the next larger element of any other element because of i.
So, next larger elements forms a chain maintained by the queue starting from the end of it.
The next larger element is the element at the end of the queue or -1 if the queue is empty - i.e. element i has no larger elements on its right.

## Complexity

The algorithm scans the array only once. Furthermore, each element is pushed and removed only once, so the number of push and pop operations are at most O(n). So, the overall time complexity is O(n).
