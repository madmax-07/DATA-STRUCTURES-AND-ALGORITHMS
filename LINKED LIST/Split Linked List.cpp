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
    int find_len(ListNode*head){
        if(head==NULL)
            return 0;
       int count=0;
        ListNode*p=head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        if(head==NULL)
        {while(k--)
            ans.push_back(NULL);
            return ans;}
        int len=find_len(head);
        cout<<len<<"l"<<endl;
        if(k>=len){
            ListNode*p=head;
            while(p!=NULL)
        {   ans.push_back(p);
            ListNode*Next=p->next;
            p->next=NULL;
            p=Next;
        }
        
            int count=k-len;
            while(count--){
                ans.push_back(NULL);
            }
            return ans;
        }
     else if(len>k){
        int size=len/k; //10/3=3-> 3 parts each of len 3
        int rem=len%k;  //11/6 =1->each part of len 1 and 5 is remaining 
        ListNode*p=head;
        
        while(k--){
            //cout<<p->val;
            ans.push_back(p);
            int count=0;
            ListNode*prev=NULL;
            while(count<size and p!=NULL){
                count++;
                prev=p;
                p=p->next;
            }
           
            if(rem>0 and p!=NULL){
                rem-=1;
                prev=p;
                p=p->next;
            }
            prev->next=NULL;
        }
     }
        return ans;
        
        
        
        
    }
};
