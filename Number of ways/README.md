# Number of ways

## Solution

In order to admit a valid partition, the sum of the elements of the input array must be divisible by 3, otherwise, no partitioning can be found.

Let S be the sum of all elements in the input array.
First of all, we compute the array C: the i-th position of this array contains the number of suffixes that sum to S / 3 up to position i.

Then we compute for each position j the sum of prefixes up to j. Every time the sum of the elements in the range [0-j] sum to S / 3, we discover a new first subset that can be part of a solution. So, we can add to the result the value at position C[j + 2]. In fact, C[j + 2] store the number of suffixes that sum to S / 3: as the first range sum to S / 3, it must be the case that also the central range sum up to S / 3 (S is divisible by 3), and the partitioning found is valid.

## Complexity

The algorithm performs three main operations:

- Compute the sum of the elements: theta(n)
- Compute the sum of the number of suffixes that sum to S / 3: theta(n)
- Compute the prefix sums and check for valid partitioning: theta(n)

So, the overall complexity is theta(n) time using O(n) additional space to store the array C.
