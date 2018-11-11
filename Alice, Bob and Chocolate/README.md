# Alice, Bob and Chocolate

The problem is solvable computing the prefix sums of the elements for both Alice and Bob. Alice start summing up elements from the first and Bob starts from the last. In facts, the ith sum is the starting eating time for the ith bar. Those values give us the information about who is free to take a new element.

The algorithm starts setting two pointers, one at the begin and one at the end of the vector containing the elements, respectively for Alice and Bob.
Then, it computes the sums on the fly by summing the lower of the two values referenced by the pointers to the respective sum and moving forward the pointer in case of Alice and backward in case of Bob.

When the two pointers flip their side, the pointers indicate values that are already taken by the other player. So the algorithm stops and report the count of the elements for both Alice and Bob as result.

# Complexity

The algorithm scans the element only once and in each iteration performs only constant-time operations. Then, the overall complexity is theta(n) using no additional space.