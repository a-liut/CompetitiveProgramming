# Finding Team Member

The key point to solve the problem is the fact that the teammates with the highest strength are for sure copuled.

So, we just keep the strenghts ordered tagged with the informations about the contestant - their indexes. This job is implemented using a priority queue.
Then, items are extracted from the queue until all teams are assigned.

# Complexity

The algorithm insert into the queue all the items at most one time and pop all of them in the worst case. theta(nlogn) are required to build up the queue.

So the algorithm takes theta(n + nlogn) = theta(nlogn) time and theta(n) additional space for the queue.