#include <bits/stdc++.h>
using namespace std;
int main()
{ // this defines the use of forward list
    // forward_list is used  to implement a single linked list

    //declaring a forward list
    forward_list<int> list1;
    forward_list<int> list2;

    //assign()-used to assign values to the fl
    list1.assign({1, 2, 3, 4});

    //method 2 to use assign 3 elements with value 7
    list2.assign(3, 7);
    for (auto x : list1)
        cout << x << "->";

    //assign insert element at the first position on the forward list
    list1.push_front(10);

    //deletes the first element in the list
    list.pop();
    for (auto x : list1)
        cout << x << endl;



}