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
     class Pair
  {
  public:
    bool has_cam;
    bool need_cam;
  };
  int ans = 0;
  Pair helper(TreeNode *root)
  {
    Pair p;
    if (root == NULL)
    {
      p.has_cam = false;
      p.need_cam = false;
      return p;
    }
    Pair lp = helper(root->left);
    Pair rp = helper(root->right);
    if (lp.need_cam || rp.need_cam)
    {
      p.has_cam = true;
      p.need_cam = false;
      ans++;
    }
    else if (!lp.need_cam and !rp.need_cam)
    {
      if (lp.has_cam || rp.has_cam)
      {
        p.has_cam = false;
        p.need_cam = false;
      }
      else if(!lp.has_cam and !rp.has_cam)
      {
        p.has_cam = false;
        p.need_cam = true;
      }
    }
    return p;
  }
    
    int minCameraCover(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left==NULL and root->right==NULL)return 1;
         Pair p=helper(root);
        if(p.need_cam)
            ans++;
         return ans;        
    
    }
};
