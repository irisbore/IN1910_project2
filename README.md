# H20_project2_irissb_alicemj

Operation:                array_list:           linked_list:
get i                     O(1)                  O(n)     
insert front              O(n)                  O(1)
append                    O(1)                  O(1)
insert middle             O(n)                  O(n)                      
remove front              O(n)                  O(1)  
remove back               O(1)                  O(1)
remove middle             O(n)                  O(n)  
print                     O(n)                  O(n)


Comments:
Get i is O(1) in array_list because index is accessed directly,
and O(n) in linked_list because we access index by iterating through the list.

Insert front is O(n) in array_list because we iterate backwards throughout the
list to reach the front, while linked_list is O(1) because we directly access head.

Append is O(1) in array_list because we access directly from behind, while
linked_list is O(1) because we access tail directly.

Insert middle is O(n) in both array_list and linked_list because it is O(n/2),
but linear n/2 is written as n. it is n/2 because we iterate through half of
the list.

Remove front is O(n) in array_list because we have to push all the elements one
index down, while linked_list is O(1) because we access head directly.

Remove back is O(1) in array_list because we only have to move one element down,
while linked_list is O(1) because we access tail directly.

Remove middle is O(n) in both array_list and linked_list because it is O(n/2),
but linear n/2 is written as n.

Print is O(n) in both array_list and linked_list because we have to able to
reach all the elements.


Exercise 4g)
68
