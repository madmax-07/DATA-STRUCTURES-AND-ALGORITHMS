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
    cout << endl;
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
node *deleteDuplicates(node *head)
{
    //base case
    if (head == NULL or head->link == NULL)
        return head;
    node *p = head;
    while (p->link != NULL)
    {
        node *q = p->link;
        if (q->data == p->data)
        {
            node *temp = q->link;
            delete q;
            q = temp;
            p->link = q;
        }
        else
        {
            p = p->link;
        }
    }
    return head;
}

int main()
{
    node *head = NULL;
    head = take_input(head);

    print(head);

    head = deleteDuplicates(head);
    print(head);
}
