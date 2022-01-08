#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node(int d)
    {
        data = d;
        link = NULL;
    }
};
// globally declared head so that any chnaged made are recorded
Node *head = NULL;
void push(int d)
{
    Node *temp = new Node(d);
    temp->link = head;
    head = temp;
}
void pop()
{
    if (head == NULL)
    {
        cout << "error" << endl;
        return;
    }
    Node *temp = head;
    head = head->link;
    temp->link = NULL;
    delete temp;
}
int top()
{
    if (head == NULL)
    {

        return -1;
    }
    return head->data;
}
bool isempty()
{
    return head == NULL;
}
void display()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->link;
    }
    cout << endl;
}
int main()
{
    push(1);
    push(2);
    push(3);
    cout << "elemnt at the top of stack is :" << top() << endl;
    push(4);
    push(5);
    display();
    pop();
    pop();
    display();
}
