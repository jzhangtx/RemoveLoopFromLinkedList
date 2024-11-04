Remove Loop From Linked List

Given a linked list, remove the loop if it exists.

You need to find the last node of the list that points to one of its previous nodes and make it point to NULL.

input: 1 -> 7 -> 3 -> 6 -|
            ^            |
            |------------|

Output: 1 -> 7 -> 3 -> 6

Remove Loop From Linked List
Testing
Input Format
First line contains ‘T’, denoting the number of independent test cases.

For each test case, the input has three lines:

A number ‘n’, denoting the length of the linked list.
n space-separated integers denoting the elements of the linked list. 
A number denoting the position of the node to which the last node is connected.
Output Format
For each test case, it contains a line with n space space-separated integers denoting elements of the linked list.

Sample Input
5
3
3 4 5
1
5
1 2 3 4 5
2
4
67 54 890 32
4
2
23 45
-1
0

-1
Expected Output
3 4 5
1 2 3 4 5
67 54 890 32
23 45