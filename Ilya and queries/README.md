# Ilya and queries

The problem that have to be solved is prefix sum. To achive better performance, a BIT is used to perform the queries.

The algorithm starts building the BIT using the string given in input. Note that the bit uses an array of exacly n positions in order to count the leftmost element only once.
For each element, the position of the character is updated by 1 w.r.t. the given predicate (s[i] === s[i + 1]).

Then the result of a query is computed as the sum of the matching elements up to the end of the range minus the sum of the elements up to the begin of the range. The sum is started looking at the previous position thatn the requested element because the leftmost element should be considered only once and the rightmost element should not be considered at all due to a constraint of the problem.

# Complexity

In order to define the complexity, we need to evaluate the time for building the BIT and the time to answer to a query.
The algorithm builds the BIT incrementally, adding 1 one by one for each element. So, the construction of the BIT takes theta(nlog n) time.
The query requires 2 sum operation on the BIT and each one takes theta(log n), so theta(2log n) = theta(log n).

Summing up, the overall complexity of the algorithm is theta(nlog n) time using theta(n) additional space to store the BIT.
