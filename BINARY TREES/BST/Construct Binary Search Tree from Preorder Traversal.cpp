question link :https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


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
/*Approach: traverse the array and do a preorder traversal keeping in mind that in bst nodes to the left of bst are in range [0,root->val) and nodes to right of bst are in range [root->val+1, MAX].
*/

class Solution {
public:
    TreeNode*solve(vector<int>&v,int&i,int min,int max){ //passing i (which keeps track of the array index) with refrence .
        
        TreeNode*root=new TreeNode();
        if(i==v.size()) //base condition when i reaches the end of the array 
            return NULL;
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
