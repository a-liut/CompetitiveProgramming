# Leaders in an array

The solution simply scans the vector from end to start and keep the maximum element found.
For every element, just compare the element with the maximum element found: if it is greater thatn the maximum, update the maximum and declare it as a leader by pushing it into a stack.
At the end, just pop the elements from the stack to get the ordered sequence of leaders.

So, the algorithm runs in O(n) time since it scan all elements once a time.