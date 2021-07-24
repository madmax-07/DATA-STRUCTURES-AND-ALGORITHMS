/*The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
/* 
Approach
basically we have to delete the current node if it has any greater node towards its right
* (Not just towards it immediate right but all of the right side)
i/p: 14->3->7->6->12->10
o/p: 14->12->10 
[ 3 has 7,6,12 10 
  7 has 12,10 
  6 has 12
 ]
traverse the list from the start and delete the node when the current Node < next Node. To delete the current node, follow this approach. 

Let us assume you have to delete current node X 

1. Copy next node’s data into X i.e X.data = X.next.data

2. Copy next node’s next address i.e X.next = X.next.next;

Move forward in the List only when the current Node is > the next Node.
 To check for current towrads it right I will recursivelly solve the problem 
 10->12->13->14->15
 10->(12->13->14->15)
 12->(13->14->15)
 13->(14->15)
 14->(15)
 15
*/
class Solution
{
    public:
      Node *compute(Node *head)
{
    //base condition
    if (head == NULL or head->next == NULL)
        return head;
    compute(head->next);
    if (head->next->data > head->data)
    {
        Node *temp = head->next;
        head->data = temp->data;
        head->next = temp->next;
        delete temp;
    }
    return head;
}
    
};
