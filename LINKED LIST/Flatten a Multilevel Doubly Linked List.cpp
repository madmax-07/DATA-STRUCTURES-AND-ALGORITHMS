/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
          return head;
        Node*Prev=NULL;
        stack<Node*>s;
        s.push(head);
        while(!s.empty()){
            Node*p=s.top();
            s.pop();
            if(Prev!=NULL)
            {Prev->next=p;
                p->prev=Prev;
            }   
            while(p!=NULL){
                if(p->child!=NULL){
                    if(p->next)
                    s.push(p->next);
                    p->next=p->child;
                    p->child->prev=p;
                    p->child=NULL;
                   }
                
                Prev=p;
                p=p->next;
            }
        }
        return head;
    }
};
