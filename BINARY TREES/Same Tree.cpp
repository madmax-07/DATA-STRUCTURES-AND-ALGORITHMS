/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
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
    void help(TreeNode* p, TreeNode* q){
        if(!p and !q)
            return;
        if(!p ||!q)
        {   ans=false;
            return;
        }
        if(p->val!=q->val)
        {ans= false;
        return;
        }
        if(ans)
        help(p->left,q->left);
        if(ans)
        help(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        help(p,q);
            return ans;
    }

};
