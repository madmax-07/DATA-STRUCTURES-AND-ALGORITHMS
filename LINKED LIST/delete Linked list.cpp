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

void insertAtTail(node *&head, int d)
{
    node *n = new node(d);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *current = head;
    while (current->link != NULL)
        current = current->link;
    current->link = n;
}
void insertInMiddle(node *&head, int d, int p) //insert at pos
{
    node *n = new node(d);
    if (p == 0 or p == 1)
    {
        insertAtHead(head, d);
        return;
    }
    else if (p > length(head))
    {
        insertAtTail(head, d);
        return;
    }
    else
    {
        node *current = head;
        int jump = 1;
        while (jump < p - 1)
        {
            current = current->link;
            jump++;
        }
        n->link = current->link;
        current->link = n;
    }
}
void deleteAthead(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head->link;
    delete head;
    head = temp;
}
void deleteAttail(node *&head)
{
    if (head == NULL)
        return;
    else if (head->link == NULL)
        deleteAthead(head);
    else
    {
        node *p = head;
        while (p->link->link != NULL)
            p = p->link;
        node *target = p->link;
        delete target;
        p->link = NULL;
    }
}
void deleteAtmiddle(node *&head, int p)
{
    if (p == 1 or p == 0) //
        deleteAthead(head);
    else if (p == length(head))
        deleteAttail(head);
    else
    {
        int jump = 1;
        node *current = head;
        while (jump <p - 1)
        {
            current = current->link;
            jump++;
        }
        node *target = current->link;
        current->link = current->link->link;
        delete target;
    }
}
int main()
{
    node *head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    cout << endl;
    insertInMiddle(head, 4, 3); //insert at position 3
    insertAtTail(head, 7);
    print(head);
    cout << endl;
    deleteAthead(head);
    deleteAttail(head);
    print(head);
    cout << endl;
    deleteAtmiddle(head, 3);//deletes from position 3
    print(head);
    cout << endl;
}