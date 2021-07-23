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
    ListNode* removeNthFromEnd(ListNode* head, int k) 
        
    {
    ListNode *fast = head;
    ListNode *slow = head;
    int pos = 0;
    while (pos < k)
    {
        fast = fast->next;
        pos++;
    }
    if (fast == NULL) //If after the above step fast takes a lead of k an dpoints to NULL that means k==len 
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}
};
