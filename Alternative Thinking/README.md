# Alternative Thinking

## Solution

The longest alternating subsequence can be found by scanning the sequence from left to right checking the occurrences of either 0 and 1.
If the length longest alternating subsequence is less than $n$, it means that at some point there is an occurrence of two consecutive 0  or 1 in the sequence. Swapping from that point, the length of the subsequence increases by 2. So the answer is the minimum between $n$ and the length of the longest alternating subsequence plus 2.

## Complexity

This greedy algorithm processes each element exactly once and it performs only constant time operations during the scan.
Therefore, the time complexity of the algorithm is $\Theta(n)$.