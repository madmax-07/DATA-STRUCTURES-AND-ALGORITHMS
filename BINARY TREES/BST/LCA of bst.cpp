/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*Concept:
1.if one value lies in smaller than the root and the other greater than the the root 
*/

class Solution {
public:
    TreeNode*help(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL)
            return NULL;
        if(p->val>=root->val and q->val<=root->val ||p->val<=root->val and q->val>=root->val){
            return root; //if one value lies in smaller than the root and the other greater than the the root 
        }
        else if(p->val <root->val and q->val<root->val)
            return help(root->left,p,q);
        return help(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        return help(root,p,q);
        }
};
