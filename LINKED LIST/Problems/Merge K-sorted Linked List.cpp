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
ListNode *merge(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;
    ListNode *c;
    if (h1->val <= h2->val)
    {
        c = h1;
        c->next = merge(h1->next, h2);
    }
    else if (h1->val > h2->val)
    {
        c = h2;
        c->next = merge(h1, h2->next);
    }
    return c;
}
ListNode *mergesort(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    ListNode *mid = middle(head);
    ListNode *a = head;
    ListNode *b = mid->next;
    mid->next = NULL;
    a = mergesort(head);
    b = mergesort(b);
    head = merge(a, b);
    return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    ListNode *result = NULL;
    ListNode *dummy = new ListNode(-1);
    ListNode *x = dummy;
    for (int i = 0; i < lists.size(); i++)
    {
        ListNode *p = lists[i];
        while (p != NULL)
        {
            x->next = p;
            x = x->next;
            p = p->next;
        }
    }
    x->next = NULL;
    x = mergesort(dummy->next);
    delete dummy;
    return x;
}
};
