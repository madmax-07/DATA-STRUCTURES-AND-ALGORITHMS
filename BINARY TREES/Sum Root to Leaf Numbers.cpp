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
    void help(TreeNode*root,vector<string>&ans,string path){
        if(root==NULL)
            return;
        path+=to_string(root->val);
        if(!root->left and !root->right){
            ans.push_back(path);
            return;
        }
        
        help(root->left,ans,path);
        help(root->right,ans,path);
    }
    int sumNumbers(TreeNode* root) {
        vector<string>ans;
        help(root,ans,"");
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=stoi(ans[i]);
        }
        return sum;
    }
};
