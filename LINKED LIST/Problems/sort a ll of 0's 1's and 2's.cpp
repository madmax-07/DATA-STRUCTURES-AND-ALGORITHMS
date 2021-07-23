class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
   Node *segregate(Node *head)
{
    Node *zeroD = new Node(0);
    Node *oneD = new Node(0);
    Node *twoD = new Node(0);
    Node *zero = zeroD;
    Node *one = oneD;
    Node *two = twoD;

    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        else if (curr->data == 2)
        {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    zero->next = (oneD->next != NULL) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;
    head = zeroD->next;
    delete zeroD;
    delete oneD;
    delete twoD;
    return head;
}

    
};
