//question link https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

/*struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
Node*prev=NULL;
void help(Node*root){
    if(root==NULL)
    return;
    help(root->left);
    if(prev==NULL)
    prev=root;
    else if(prev!=NULL){
        prev->next=root;
        prev=root;
    }
    help(root->right);
}
public:

    void populateNext(Node *root)
    { if(root==NULL)
        return ;
        help(root);
        
    }
};
/*Time complecity :O(h)
 space complexity:O(h) recurssive stack space 
 */
