/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*,Node*>mp;
    Node*create(Node*head,Node*&head2){
        if(head==NULL)
            return NULL;
        Node*temp=new Node(head->val);
        mp[head]=temp;
        if(head2==NULL)
           head2=temp;
        temp->next=create(head->next,head2);
        return temp;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        //Step 1 create  a copy of the linked list 
        Node*head2=NULL;
        create(head,head2);
        Node*temp=head2;
        while(temp!=NULL)
        {  temp->val;
            temp=temp->next;;
        }
        Node*p=head;
        while(p!=NULL){
                Node*curr=mp[p];
                if(p->random==NULL)
                    curr->random=NULL;
                else 
                    curr->random=mp[p->random];
            p=p->next;
    }
        return head2;
        
    }
};
