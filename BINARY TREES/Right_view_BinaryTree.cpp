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
  vector<int> rightSideView(TreeNode *root)
{   vector<int>v;
    if (root == NULL)
        return v;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            TreeNode *ptr = q.front();
            q.pop();
            if (ptr->left)
            {
                q.push(ptr->left);
            }
            if (ptr->right)
            {
                q.push(ptr->right);
            }
            if(i==size){
                v.push_back(ptr->val);
            }
        }
        
    }
    return v;
}
};
