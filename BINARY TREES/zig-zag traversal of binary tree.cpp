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
   vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{   
    vector<vector<int>> v;
       if(root==NULL)
           return v;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
       s1.push(root);
    while (!s1.empty() or !s2.empty())
    {
        vector<int> ans;
        while (!s1.empty())
        {
            TreeNode *ptr = s1.top();
            s1.pop();
            ans.push_back(ptr->val);
            if (ptr->left)
            {
                s2.push(ptr->left);
            }
            if (ptr->right)
                s2.push(ptr->right);
        }
        if(!ans.empty())
        v.push_back(ans);
        ans.clear();
        while (!s2.empty())
        {
            TreeNode *ptr = s2.top();
            s2.pop();
            ans.push_back(ptr->val);
            
            if (ptr->right)
                s1.push(ptr->right);
            
            if (ptr->left)

                s1.push(ptr->left);

        }
        if(!ans.empty())
        v.push_back(ans);
        ans.clear();
    }
       return v;
}
};
