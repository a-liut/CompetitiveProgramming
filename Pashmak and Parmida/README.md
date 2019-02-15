# Pashmak and Parmida's Problem

## Solution

The idea is to precompute, for each position values of $f(j, n, a_j)$ counting the occurrencies of $a_j$. With those values, the algorithm builds a BIT $B$ adding 1 to to $B[k]$. This means that $Sum(k)$ will give us the number of times that the function $f(j, n, a_j) \leq k$.

Now the algorithm has to check whether $f(i, n, a_i) > f(j, n, a_j)$.
Let $k = f(i, n, a_i)$ that can be computed in the same way of $f(j, n, a_j)$. By performing $Sum(k - 1)$, the algorithm knows how many times $f(i, n, a_i) > k = f(j, n, a_j)$. However, we need to discard occurrences of $a_i$ in prefix $[1, i]$ as they are outside of the interval $[j, n]$. Thus, we subtract $1$ to $f(i, n, a_i)$ to obtain the correct answer.

## Complexity

The algorithm scans the sequence two times ($\Theta(n)$) adding elements to a BIT and summing up prefixes ($O(logn)$). Thus, its time complexity is $O(nlogn)$ using additional $O(n)$ space to store the BIT and counters.