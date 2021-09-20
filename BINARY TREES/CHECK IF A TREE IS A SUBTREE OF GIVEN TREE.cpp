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
    bool check(TreeNode*r1,TreeNode*r2){
        if(!r1 and !r2){
            return  true;
        }
        if((!r1 and r2) || (r1 and !r2))
            return false;
        if(r1->val !=r2->val)
            return false;
        return (check(r1->left,r2->left) and check(r1->right,r2->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* p) {
        if(!root && !p)
            return true;
        if((!root and p) ||(!p and root))
            return false;
        //agar dono non null h
        if(root->val==p->val){
            if(check(root,p))
                return true;
        }
        return(isSubtree(root->left,p) || (isSubtree(root->right,p)));
        
    }
};
