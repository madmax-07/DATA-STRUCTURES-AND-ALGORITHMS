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
    void deleteNode(ListNode* node) {
        if(node==NULL)
            return ;
        node->val=node->next->val;
        ListNode*p=node->next;
        node->next=node->next->next;
        // p->next=NULL;
        delete p;
    }
};
