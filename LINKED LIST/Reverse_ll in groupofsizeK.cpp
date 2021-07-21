/*PROBLEM STATMENT
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k
then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

/* APPROACH -
S1: FIND THE SIZE OF THE LL
S2: FIND HOW MANY GROUPS OF SIZE K CAN BE FORMED? ->N=SIZE/K
S3: REVERSE THE N GROUPS FORMED ABOVE IN EACH K AT A TIME 
*/

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *link = NULL;
    node(int d)
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
node *take_input(node *head)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        node *n = new node(d);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *p = head;
            while (p->link != NULL)
            {
                p = p->link;
            }
            p->link = n;
        }
        cin >> d;
    }
    return head;
}
node *reverseGroup(node *head, int k, int s)
{
    if (s == 0)
        return head;

    node *current = head, *prev = NULL, *next;
    int count = k;
    while (current != NULL and count > 0)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
        count--;
    }
    if (next != NULL)
    {
        head->link = reverseGroup(current, k, s - 1);
    }
    return prev;
}
node *reverseKGroup(node *head, int k)
{
    int size = 0;
    node *p = head;
    while (p != NULL)
    {
        size++;
        p = p->link;
    }
    int s = size / k;
    head = reverseGroup(head, k, s);
    return head;
}

int main()
{
    node *head = NULL;
    head = take_input(head);

    print(head);
    int k;
    cin >> k;

    head = reverseKGroup(head, k);
    print(head);
}
