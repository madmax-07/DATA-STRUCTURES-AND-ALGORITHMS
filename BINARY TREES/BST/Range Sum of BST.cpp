//question link: https://leetcode.com/problems/range-sum-of-bst/submissions/

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
    int sum=0;
  bool inrange(int data,int low,int high)
    { return (data>=low and data<=high);
}
    void find_sum(TreeNode*root,int low,int high){
        if(root==NULL)
            return;
        if(inrange(root->val,low,high))
            sum+=root->val;
        find_sum(root->left,low,high);
        find_sum(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
     find_sum(root,low,high);
    return sum;
    }
};
/* tc: O(h)=O(n)
  sc:O(h)
  */
