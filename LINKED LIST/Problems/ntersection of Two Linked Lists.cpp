/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
 int length(ListNode *head)
{
    int count = 0;
    while (head != NULL)
    {count++;
     head=head->next;}
    return count;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL or headB == NULL)
        return NULL;
    int l1 = length(headA);
    int l2 = length(headB);
    int k = l1 - l2;
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    //assuming that list one is the greater
    if (k < 0)
    {
        p1=headB;
        p2=headA;
    }
    int count=abs(k);
    while (count > 0)
    {
        p1 = p1->next;
        count--;
    }
    while (p1 != NULL and p2 != NULL)
    {
        if (p1 == p2)
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
};
