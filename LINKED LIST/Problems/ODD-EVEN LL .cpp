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
//sol approach - use dummy nodes 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode*tempO=new ListNode(0);
        ListNode*mo=tempO;
        ListNode*tempE=new ListNode(0);
        ListNode*me=tempE;
        ListNode*p=head;
        int index=1;
        while(p!=NULL){
            if(index%2!=0){
                mo->next=p;
                mo=mo->next;
            }
            else if(index%2==0){
                me->next=p;
                me=me->next;
            }
            p=p->next;
            index++;
        }
    me->next=NULL;
    mo->next=tempE->next;
    tempE->next=NULL;
    delete tempE;
    head=tempO->next;
    delete tempO;
    return head;
    }
};
//Time complexity-O(n)
//Space complexity -O(1)
