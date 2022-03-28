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
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node*curr=head;
        while(curr!=NULL){
            Node*temp=new Node(curr->val);
            Node*Next=curr->next;
            temp->next=Next;
            curr->next=temp;
            curr=Next;
        }
        curr=head;
        while(curr!=NULL){
            Node*n=curr->next;
            if(curr->random==NULL)
                n->random=NULL;
            else 
                n->random=curr->random->next;
            curr=curr->next->next;
        }
        curr=head;
        Node*prev=NULL,*head2=NULL;
        while(curr!=NULL){
            Node*n=curr->next;
            curr->next=n->next;
            if(head2==NULL)
                head2=n;
            if(prev!=NULL)
                prev->next=n;
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
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node*curr=head;
        while(curr!=NULL){
            Node*temp=new Node(curr->val);
            Node*Next=curr->next;
            temp->next=Next;
            curr->next=temp;
            curr=Next;
        }
        curr=head;
        while(curr!=NULL){
            Node*n=curr->next;
            if(curr->random==NULL)
                n->random=NULL;
            else 
                n->random=curr->random->next;
            curr=curr->next->next;
        }
        curr=head;
        Node*prev=NULL,*head2=NULL;
        while(curr!=NULL){
            Node*n=curr->next;
            curr->next=n->next;
            if(head2==NULL)
                head2=n;
            if(prev!=NULL)
                prev->next=n;
             prev=n;
             curr=n->next;
        }
        return head2;
    }
        
};             curr=n->next;
        }
        return head2;
    }
        
};
