#include <bits/stdc++.h>
using namespace std;
// There are two ways :
// Either create a LinkedList class (Object oriented Approach)
// or do separately in functions (Procedure oriented Approach)

// We'll prefer the latter one since its the one asked in interviews.
class node
{
public:
    int data;
    node *link;
    node(int d) // constructor to initialise the values
    {
        data = d;
        link = NULL;
    }
};
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->link;
    }
}
int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->link;
    }
    return count;
}

void insertAttail(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    { //we will always check the base case
        head = n;
        return;
    }
    node *p = head;
    while (p->link != NULL)
        p = p->link;
    p->link = n;
    n->link = NULL;
}

void take_input(node *&head)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        insertAttail(head, d);
        cin >> d;
    }
}
//------------OPERATOR-OVERLOADING---------------------------------------------------------------------------------

// CIN >> OPERATOR OVERLOADED
istream &operator>>(istream &is, node *&head) /* take a node that we return the cin object else it returns void and we wont 
                                             able to take cin>>head2>>head2. THIS IS Known as Cascading of operators*/
{
    take_input(head);
    return is;
}

//COUT <<OPERATOR OVERLOADED
ostream &operator<<(ostream &os, node *head) /*we return the cout obeh=jcet to be able to use cout<<head1<<head 2 */
{
    print(head);
    return os;
}
//---------------END OF OPERATOR OVERLOADING FUNCTIONS-------------------------------------------------------------
/* MERGE TWO SORTED LINKED LIST
SOLUTION 

 - Take a third pointer and make recursive calls to the merge function 


*/
node *find_midpoint(node *head)
{
    if (head == NULL or head->link == NULL)
        return head;
    node *slow = head;
    node *fast = head->link;
    while (fast != NULL and fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
    }
    return slow;
}

node *merge_sorted_linkedlist(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    node *c;
    if (head1->data < head2->data)
    {
        c = head1;
        c->link = merge_sorted_linkedlist(head1->link, head2);
    }
    else
    {
        c = head2;
        c->link = merge_sorted_linkedlist(head1, head2->link);
    }
    return c;
}
node *mergesort(node *head)
{ //BASE CASE: IF WE ARE LEFT WITH A SINGLE NODE OR HAVE AN EMPTY LIST
    if (head == NULL or head->link == NULL)
        return head;
    //STEP 1:BREAK

    node *mid = find_midpoint(head);
    node *a = head;
    node *b = mid->link;
    mid->link = NULL;

    //STEP 2: RECCURSIVLEY SORT TWO PARTS
    a = mergesort(a);
    b = mergesort(b);

    // STEP 3 :MERGE THEM
    node *c = merge_sorted_linkedlist(a, b);
    return c;
}

int main()
{
    node *head = NULL;
    cin >> head;
    cout << head << endl;
    head = mergesort(head);
    cout << "list after sorting out is" << endl;
    cout << head << endl;
}
