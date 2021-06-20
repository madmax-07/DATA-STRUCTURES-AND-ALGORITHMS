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

int search(node *head, int key)
{
    int pos = 1;
    while (head != NULL)
    {
        if (head->data == key)
            return pos;
        else
        {
            head = head->link;
            pos++;
        }
    }
    return -1;
}
int recursive_search(node *&head, int key)
{
    if (head == NULL)
        return -1;

    if (head->data == key)
        return 1;

    int i = search(head->link, key);
    if (i != -1)
        return i + 1;
    else
        return -1;
}
int main()
{
    node *head = NULL;

    /*head = take_input();*/

    cin >> head; // cin operator overloaded

    //cout operator overloaded
    cout << head << endl;
    int key;
    cin >> key;
    int i = recursive_search(head,key);
    if (i == -1)
        cout << "key not found"<<endl;
    else
        cout << "key found at position " << i << endl;
}