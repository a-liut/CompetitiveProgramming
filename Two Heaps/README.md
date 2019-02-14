# Two Heaps

## Solution

The number of possible different numbers that can be build using the two heaps is equal to the product of the size of the two heaps.

However, if the same number appears multiple times into the same heap, this number decreases as we need to count only distinct four digits numbers. So, the algorithm needs to try to put duplicate numbers in different heaps.

First of all, the algorithm sort the sequence. In this way, instances of the same numbers are grouped together.

Then, it processes elements one by one, checking if the current element is equal to the previous one.

The algorithm stores d_heap[1] and d_heap[2] the number of elements of heap one and two respectively.
When a new element appears, the element is put into the more empty heap. When an element appears twice, it is put into the other heap. Other instances of the number are ignored as they do not increase the number of combination possible.

## Complexity

The algorithm time complexity is dominated by the sorting operation. The overall time complexity is $O(nlogn + n) = O(nlogn)$ and the algorithm uses $\Theta(n)$ additional space.