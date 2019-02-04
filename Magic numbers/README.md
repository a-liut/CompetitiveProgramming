# Magic numbers

## Solution

The algorithm simply scans the characters composing the number from left to right and at each step, checks whether a magic number is recognized.
A magic number starts with a '1' and it is followed by at most 2 occurrences of '4'. The algorithm maintains a counter to count the number of occurrences of the character '4' after an occurrence of '1'.

Let $c_i$ be the i-th character read from the input. Then, if $c_i$ is equals to '1', then the counter is set to 0. If $c_i$ is equals to '4' and the counter is less than 2, then the counter is increased by one. In all the other cases, the algorithm reports that the number is not a magic one.

## Complexity

The algorithm applies a simple greedy strategy scanning the character composing the number once. Thus, the running time of the algorithm is $\Theta(n)$ where $n$ is the number of digits composing the number.