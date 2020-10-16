# H20_project2_irissb_alicemj

#Link to repo
https://github.uio.no/IN1910/H20_project2_irissb_alicemj.git

#Commands used to compile the code
c++ -std=c++11 -Wall array_list.cpp -o ArrayList

c++ -std=c++11 -Wall linked_list.cpp -o LinkedList

c++ -std=c++11 -Wall cirular_linked_list.cpp -o CirkLinklist

#Exercise 3)
Comments:

Get element i: The Big-oh notation is O(1) in array_list because index is accessed directly,
and O(n) in linked_list because we access an index by iterating through the list.

Insert front: The Big-oh notation is O(n) in array_list because we iterate backwards throughout the
list to reach the front, while linked_list is O(1) because we directly access head.

Append: The Big-oh notation is O(1) in array_list because we access the last index directly, while
linked_list is O(1) because we access tail directly.

Insert middle: The Big-oh notation is O(n) in both array_list and linked_list because it will take n/2
operations to reach the index, but since n/2 is still linear it is written as O(n). It is n/2 because we only iterate 
through half of the list to reach the index in middle.

Remove front: The Big-oh notation is O(n) in array_list because we have to push all the elements one
index down, while linked_list is O(1) because we access head directly.

Remove back: The Big-oh notation is O(1) in array_list because we don't have to move any element down,
while linked_list is O(1) because we access tail directly.

Remove middle: The Big-oh notation is O(n) in both array_list and linked_list because it takes n/2 operations
to either push half of the list an index down as in array_list or to iterate through half of the list as in
linked_list, and since n/2 is linear we write the Big-oh notation as O(n).

Print: The Big-oh notation is O(n) in both array_list and linked_list because we have to be able to
reach all the elements in the list.


Exercise 4g)
The answer is 68
