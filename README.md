# Some-C-Programs

**Between Two Sets**

www.hackerrank.com/challenges/between-two-sets/problem

**Divisible Sum Pairs**

https://www.hackerrank.com/challenges/divisible-sum-pairs/problem

**Binary Search Tree Operations using Recursion**

Binary Search Tree is a node-based binary tree data structure which has the following properties:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.
There must be no duplicate nodes.

**Dining Philosophers Problem**

Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.

Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.

Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.

The problem is how to design a discipline of behavior (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.

**File operations in C**

This is a program to Add, Search, Delete and Display records of students stored in a text file.

**Hash Tables chaining with Singly Linked Lists**

This is a C Program to implement hash tables using linked list. Hash table will have ‘n’ number of buckets. 
To insert a node into the hash table, we need to find the hash index for the given key. And it could be calculated using the hash function. Example: hashIndex = key % noOfBuckets 
Move to the bucket corresponds to the above-calculated hash index and insert the new node at the end of the list. To delete a node from the hash table, get the key from the user, calculate the hash index, move to the bucket corresponds to the calculated hash index, search the list in the current bucket to find and remove the node with the given key. Finally, remove the node with given key, if it is present.
