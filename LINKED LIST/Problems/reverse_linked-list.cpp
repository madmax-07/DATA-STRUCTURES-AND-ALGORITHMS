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
//iterative function to reverse a linked list
void reverse(node *&head)
{
    node *prev = NULL, *current = head, *next;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
//reccursive function to reverse a linked list
node *reverse_recursive(node *head)
{
    if (head == NULL || head->link == NULL) //base case if the list is emplty or we have reached the last nod eof the list
        return head;
    node *shead = reverse_recursive(head->link);
    /*
    node *temp = shead;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = head;
    head->link = NULL */

    //-- the following is the optimisation for the above since temp is the link of head
    head->link->link = head;
    head->link = NULL;
    return shead;
}
int main()
{
    node *head = NULL;

    /*head = take_input();*/

    cin >> head; // cin operator overloaded

    //cout operator overloaded
    cout << head << endl;
    head = reverse_recursive(head);
    cout << head;
}
