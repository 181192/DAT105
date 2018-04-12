# Exercise 3 - Priority Queue


## From DAT102:
A priority queue is a collection of elements where
the ordering is determined by two rules:
* Elements with higher priority is extracted first.
* Elements with the same priority will be extracted based on the
 “ first in first out” principle.


In this exercise you are to create a priority queue class that that satisfy the following
requirements:
The data type of the elements in the collection should be the Edge class as specified in the
code from lecture 17.


The priority rule should be that the lower edge weight, the higher priority.
The class should have the operations "add" and "remove" that respectively adds a new
element and removes the element with highest priority.
The class should also have an operation "isEmpty" that returns true if the queue is empty and
false otherwise.


### a)
Write a class definition for the class PriorityQueue with constructors, destructor and methods
to perform the operations specified above.


### b)
Overload the operator += to add a new element to the queue. += should have the same effect
as the "add" operation.