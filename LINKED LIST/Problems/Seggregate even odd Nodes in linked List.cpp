/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
       ListNode *middle(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    int pos = 1;
    ListNode *oddD = new ListNode(-1);
    ListNode *evenD = new ListNode(-1);
    ListNode *odd = oddD;
    ListNode *even = evenD;
    ListNode *p = head;
    
    while (p != NULL)
    {
        if (pos % 2!=0)
        {
            odd->next = p;
            odd = odd->next;
        }
        else if (pos % 2==0)
        {
            even->next = p;
            even = even->next;
        }
        p = p->next;
        pos++;
    }

    odd->next = evenD->next;
    even->next = NULL;
    head = oddD->next;
    delete oddD;
    delete evenD;
    return head;
}
};
