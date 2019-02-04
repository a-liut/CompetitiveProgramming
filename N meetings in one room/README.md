# N meetings in one room

## Solution

Given a set of meetings, the problem requires to select a maximal subset of them such that is conflict-free.
The algorithm applies a greedy strategy considering the meetings sorted by their finishing time.
Then, it checks all the meetings taking the first one that doesn't make conflict with the previous meeting taken.

Similarly to the Activity Selection problem, this greedy algorithm produces an optimal solution. In fact, an optimal solution contains the first meeting that finishes and the optimal selection for the other elements that finishes after that meeting are optimally chosen inductively by the algorithm.

## Complexity

The complexity of the algorithm is dominated by the cost of sorting the meetings and the cost of scanning the items which are $\Theta(nlogn)$ and $\Theta(n)$ respectively.
Therefore, the overall time complexity is $\Theta(nlogn)$.