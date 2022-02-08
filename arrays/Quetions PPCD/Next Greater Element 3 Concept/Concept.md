#### Given a number in form of string to you.Note that the length of this string can be very large which may be out of the range of long long int.
The task for you is to create a number which: 
* contains all the digits of the given number N (i.e it is some permutations of the digits N) 
* Also it is just greater than the number N (i.e smallest almong all the largest possible number possible)

##### A simple Brute Force approach will involve creating all the combinations of the given sequence of number (You can use recurssion for that) and choose the nnumber which is minimum of all the number greater than N 
Time Complexity of the above approach will be <mark>O(n!)</mark>

##### Now the concept here is that if you want to form a number which is just greater than the given number we will seek to make change stating from the unit's/one's to make the smallest possible effect of change

 
