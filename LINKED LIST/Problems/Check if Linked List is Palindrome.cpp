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
ListNode *reverse(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    ListNode*shead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}
bool isPalindrome(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return true;
    ListNode *mid = middle(head);
    ListNode *head2 = mid->next;
    mid->next = NULL;
    head2 = reverse(head2);
    while (head != NULL and head2 != NULL)
    {
        if (head -> val != head2->val)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
};
