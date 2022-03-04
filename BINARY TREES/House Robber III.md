```C++
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
    class Pair{
        public:
        int ms;
        int mns;
    };
    Pair helper(TreeNode*root){
         Pair p;   
            if(root==NULL)
            { p.ms=0;
              p.mns=0;
              return p;
            }
            Pair lh=helper(root->left);
            Pair rh=helper(root->right);
           p.ms=root->val+lh.mns+rh.mns;
           p.mns=max(lh.ms,lh.mns)+max(rh.ms,rh.mns);
           return p;
        }
    int rob(TreeNode* root) {
            
            Pair p=helper(root);
            return max(p.mns,p.ms);
    }
};
```
