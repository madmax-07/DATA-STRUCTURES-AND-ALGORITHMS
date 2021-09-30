/*question link:https://practice.geeksforgeeks.org/problems/largest-bst/1#
*/
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
  class Pair{
        public:
    bool is_bst;
    int min;
    int max;
    int size;
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
  
int msize=0;
Pair* help_findlargest(Node*root){
    Pair*p=new Pair();

    if(root==NULL){
    p->is_bst=true;
    p->min=INT_MAX;
    p->max=INT_MIN;
    p->size=0;
    return p;
    }
    Pair*lp=help_findlargest(root->left);
    Pair*rp=help_findlargest(root->right);
    p->is_bst=(lp->is_bst and rp->is_bst and (root->data>lp->max and root->data<rp->min));
    p->size=lp->size+rp->size+1;
    if(p->is_bst and p->size>msize)
        msize=p->size;
    
   
    
    p->min=min(root->data,min(lp->min,rp->min));
    p->max=max(root->data,max(rp->max,lp->max));
    return p;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	if(root==NULL)
    	return 0;
    	help_findlargest(root);
    	return msize;
    }
};
