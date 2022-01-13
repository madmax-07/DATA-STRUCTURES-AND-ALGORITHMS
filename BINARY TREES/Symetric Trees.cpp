/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans=true;
    void help(TreeNode*n1,TreeNode *n2){
        if(!n1 and !n2)
            return;
        if(!n1||!n2 ||n1->val !=n2->val)
            {ans=false;
            return;}
    
        help(n1->left,n2->right);
        help(n1->right,n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL|| root->left==NULL and root->right==NULL)
            return true;
       TreeNode*n1=root->left,*n2=root->right;
        help(n1,n2);
        return ans;
        
        
    }
};
