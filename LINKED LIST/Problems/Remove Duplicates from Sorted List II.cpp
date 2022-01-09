/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/
/* Solution Approach : USE A DUMMY NODE to maintain ditinct value sin the linked list */
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*id=head,*n;// id- index used to maintain the fist distinct node
        ListNode*dum=new ListNode(0); // make the dummy node
        ListNode*dp=dum;//pointer to the summy node 
        while(id!=NULL){
            n=id->next;
            int count=1;
          //find if there is a duplicate in the linked list corrosponding to id 
            while(n!=NULL and id->val==n->val){
                n=n->next;
                count++;
            }
          //if count==1 then no duplicates for id else there will be duplicate nodes
            if(count==1){
                dp->next=id;
                dp=dp->next;
            }
          
            id=n;
        }
      /*set dp ->next ==NULL case 1 : 1->2->2->3 (is case mai toh dp->next will automatically point to NULL)
      Case 2: 1->3->4->4 (is case mai dp->next wont point to null but would rather point to 4 [dp->1->3->4->4]
      */
        dp->next=NULL;
        head=dum->next;
        delete dum;
        return head;
        }
        
        
    
};
