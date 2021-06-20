#include <bits/stdc++.h>
using namespace std;
// There are two ways :
// Either create a LinkedList class (Object ornexted Approach)
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

void insertAtHead(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    { //we will always check the base case
        head = n;
        return;
    }
    n->link = head;
    head = n;
}

void take_input(node *&head)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        insertAtHead(head, d);
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
/* FIND THE Kth NODE FROM END IN  A LINKED LIST
   1.calculate the length of the list=N
   2.iterate until N-K
   NOTE: This approach above is O(n) but takes two iteration 

node *kthnodefromend(node *head, int k)
{
    int n = length(head);
    int jump = 0;
    while (jump != n - k)
    {
        jump++;
        head = head->link;
    }
    return head;
}
*/
/* A BETTER METHOS THAN ABOVE IS TO TAKE TWO POINTERS 
    1. FAST POINTER --> k STEPS AHEAD THAN THE SLOW POINTER 
    2. SO WHEN FAST TRAVELLS N LENGTH SLOW WILL TRAVELL N-K POSITIONS
*/
node *kthnodefromend(node *head, int k)
{
    node *fast = head;
    node *slow = head;

    int jump = 0;
    //jump k steps ahead
    while (jump != k)
    {
        jump++;
        fast = fast->link;
    }
    // now jump one 
    while (fast != NULL)
    {
        fast = fast->link;
        slow = slow->link;
    }
    return slow;
}

int main()
{
    node *head = NULL;

    /*head = take_input();*/

    cin >> head; // cin operator overloaded

    //cout operator overloaded
    cout << head << endl;
    int k;
    cin >> k;
    node *n = kthnodefromend(head, k);
    cout <<k<<" th node from end of linked-list :" << n->data;
}
