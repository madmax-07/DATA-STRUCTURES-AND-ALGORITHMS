/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 
The Method is based on the approach that in an inorder traversal we can keep a previous pointer 
lets say for a tree you have inorder traversal: 2,5,7,8,10,11 
                             previous pointers: -,2,5,7,8, 10
Now if we have to find the inorder succesoor of 5 
S1: DO an inorder traversal until you find the node (until we reach 5)
s2: when the target node for which inorder successor is found set flag=1 (indicating that the target node is found) and any further inorder traversal from here will 
    will be its successor
S3: next traversal if we have flag=1(our target node is found) and the current node is the inorder succesor so we set the prev pointer to the current root node

*/
class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
         bool flag=0;
    void solve(TreeNode*root,TreeNode*x,TreeNode*&prev){
        if(root==NULL)
        return;
        solve(root->left,x,prev);
        if(root==x)
        flag=1;
        else if(flag==1 and prev==NULL){
            prev=root;
            flag=0;
        }
        if(prev!=NULL)
        return;
        solve(root->right,x,prev);
    }
    
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * x) {
        // write your code here
         TreeNode*prev=NULL;
        solve(root,x,prev);
        return prev;
    }
};
