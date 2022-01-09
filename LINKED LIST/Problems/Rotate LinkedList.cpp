/*Question 
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]

APPOACH-
Brute Force - Rotate the linked list one by one but this  will average out to O(n^2) Tc
Optimal Sol- Given the length of the ll and the rotation factor k .SO if len=6 a nd k=4 effective rotation (Er)= 4 [4%6] if len=3 and k=4 ,ER= 4%3=1 
if len =4 and k=16 : ER=16%4=0 So we will find the effective roation by (k % len) and manipulate the links of nodes acc.
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
    ListNode*tail=NULL;
    int length(ListNode*head){
        int count=0;
        
        while(head!=NULL){
            if(head->next==NULL)
                tail=head;
            head=head->next;
            count++;
        }
        return count;
    }
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL||k==0)
        return head;
        int len=length(head);
        int r=k%len;
    if(r==0)
        return head;
    int cut=len-r;
        int size=1;
        ListNode*p=head;
        while(size!=cut){
            p=p->next;
            size++;
        }
        ListNode*temp=p->next;
        p->next=NULL;
        tail->next=head;
    head=temp;
    return head;
}
    
};
