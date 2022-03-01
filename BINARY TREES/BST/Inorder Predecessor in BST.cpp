/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
     int flag=0;
     int solve(TreeNode* root,TreeNode* t,TreeNode *&prev){
            if(root==NULL)
            return 0;
          if(solve(root->left,t,prev))
              return 1;
             if(root==t)
          {   
              return 1;
          }
          prev=root;
          return solve(root->right,t,prev);
     }
     
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here
        TreeNode*prev=NULL;
        solve(root,p,prev);
        return prev;
    }
};
