/* question link :https://www.lintcode.com/problem/1534/*/
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
    /**
     * @param root: root of a tree
     * @return: head node of a doubly linked list
     */
     TreeNode*prev=NULL;
     TreeNode*head=NULL;
     void help(TreeNode*&root){
 
    if(root==NULL)
        return;
         help(root->left);
         if(prev==NULL)
         { prev=root;
         head=root;
         }
         else if(prev!=NULL){
             prev->right=root;
             root->left=prev;
             prev=root;
         }
         help(root->right);
    }
    TreeNode * treeToDoublyList(TreeNode * root) {
        // Write your code here.
        if(root==NULL)
        return NULL;
        help(root);
        head->left=prev;
        prev->right=head;
        return head;
    }
};
/*time complexity:O(log n)
space complexity:O(log n) height of the recurssion stack
*/
