# Megacity

## Solution

In order to expand Tomsk using the minimum radius, we need to add other locations sorted by their distance - the radius - from Tomks until the megacity constraint is satisfied. This greedy approach guarantee to take the minimum solution: in fact, when Tomsk reach a certain radius, we need to add all the cities that have such a radius. Sorting locations by radius allow us to take the closest cities first producing the best sequence of locations that could be taken during the algorithm.

## Complexity

Let n be the number of cities. The algorithm performs the following steps:

1. compute the radius of each location: O(n)
2. sort locations by radius: O(n * log(n))
3. add location population the current Tomsk population: O(n)

So, the overall complexity of the algorithm is O(n * log(n)) time using O(1) additional space due to the fact that the algorithm applies the sorting algorithm directly on the original data structure without cloning it.