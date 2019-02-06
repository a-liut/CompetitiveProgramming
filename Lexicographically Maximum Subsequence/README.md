# Lexicographically Maximum Subsequence

## Solution

The lexicographically maximum subsequence (lms) can be found by scanning the sequence backward including in the answer a character if it is lexicographically lower or equal than the last added character.

This construction of the lms can be proved by induction on the length of the string:

If $n = 0$, the answer is empty as the input string and it is trivially the lms.
If $n = 1$, the answer can be $ans = s$ or $ans = \epsilon$. In this case, the algorithm chose $s$ as the answer because it is lexicographically larger than the empty string.

Now, suppose that the algorithm builds the correct lms for a sequence of $n - 1$ characters, let $s_n$ be the current item and $ans$ be the current answer computed by the algorithm so far.
We need to consider two cases:

- $max(ans) \leq s_i$: in this case, it holds that  $\forall c \in lms(n - 1). s_i \leq c$ and $\forall c \in ans. s_i \geq c$ and $s_i$ must be added to the solution, otherwise, we could find another string adding $s_i$ which is larger than the maximal found. So, $lms(n) = lms(n - 1) + s_n + ans$
- Otherwise, $s_i$ is not in lexicographically order and it should be discarded. In this case we have $lms(n) = lms(n - 1) + ans$.

Thus, this greedy algorithm produces the lms of the given string.

## Complexity

The algorithm process each element at most once, thus the running time of the algorithm is $\Theta(n)$.