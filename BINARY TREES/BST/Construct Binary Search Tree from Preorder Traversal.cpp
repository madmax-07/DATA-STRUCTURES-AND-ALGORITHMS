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
    TreeNode*solve(vector<int>&v,int&i,int min,int max){
        TreeNode*root=new TreeNode();
        if(i==v.size())
            return root;
     root->val=v[i++];
     if(i<v.size() and (v[i]>=min && v[i]<=root->val-1))
        root->left=solve(v,i,min,root->val-1);
    if(i<v.size() and (v[i]>=root->val+1 and v[i]<=max))
        root->right=solve(v,i,root->val+1,max); 
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& v) {
        int i=0;
        return solve(v,i,INT_MIN,INT_MAX);
    }
};
