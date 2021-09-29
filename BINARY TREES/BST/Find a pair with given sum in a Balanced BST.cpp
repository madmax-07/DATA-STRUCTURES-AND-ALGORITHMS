//question link: https://www.lintcode.com/problem/689/description
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /*
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
     TreeNode*prev=NULL;
     TreeNode*head=NULL;

     void modify(TreeNode*root){
         if(root==NULL)
         return;
         modify(root->left);
         if(prev==NULL){
             prev=root;
             head=root;
         }
         else if(prev!=NULL)
         { prev->right=root;
           root->left=prev;
          prev=root;
         }
         modify(root->right);
     }
    vector<int> twoSum(TreeNode * root, int n) {
        vector<int>v;
        if(root==NULL)
        return v;
        modify(root);
        root=head;
        
        
        TreeNode*p,*q;
        p=head;
        q=prev;
        
        while(p!=q ){
            if(p->val+q->val==n)
            {v.push_back(p->val);
            v.push_back(q->val);
             break;
            }
            else if(p->val+q->val<n)
            p=p->right;
            else if(p->val+q->val>n)
            q=q->left;
        }
       
        return v;
    }
};
/*time complexity 
conevrting a balanced tree to dll O(2logn)
traversing the dll to fidn the target sum O(n)
Tc:o(n)
sc :o(log) recursive stack space = h =logn in balnced tree
*/
