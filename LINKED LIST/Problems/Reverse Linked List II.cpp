/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL or head->next==NULL or left==right)
            return head;
        ListNode*lprev=NULL,*p=head;
        int count=1;
        while(p!=NULL){
            if(count==left){
                //reverse
                ListNode*curr=p,*prev=NULL,*Next;
                while(curr!=NULL and count!=right)
                { Next=curr->next;
                 curr->next=prev;
                 prev=curr;
                 curr=Next;
                 count++;
                }
                ListNode*rnext=curr->next;
                curr->next=prev;
                prev=curr;
                //change links
                if(p==head){
                    p->next=rnext;
                    head=curr;
                }
                else {
                lprev->next=curr;
                p->next=rnext;
                }
                break;
            }
            else {
                lprev=p;
                p=p->next;
                count++;
            }
        }
        return head;
        }
};
