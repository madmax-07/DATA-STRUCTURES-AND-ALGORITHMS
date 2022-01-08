/* QUESTION
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.)
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Input: head = [1]
Output: [1]
*/

 
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*curr=head,*prev=NULL,*Next;
        int size=0;
        while(curr!=NULL and size!=2){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
            size++;
        }
        head->next=swapPairs(curr);
        return prev;
        
    }
};
