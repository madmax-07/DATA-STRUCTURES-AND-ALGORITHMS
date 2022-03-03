   Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
```C++
TreeNode<int>*root2;
void helper(TreeNode<int>*root,TreeNode<int>*&prev){
    if(root==NULL)
        return;
    helper(root->left,prev);
    if( prev==NULL){
        prev=root;
        root2=root;
    }
    else if(prev!=NULL){
        prev->right=root;
        root->left=NULL;
        prev=root;
    }
    helper(root->right,prev);
    
}
TreeNode<int>* flatten(TreeNode<int>* root)
{   if(root==NULL||!root->left and !root->right)
     return root;
    TreeNode<int>*prev;
 	prev=NULL;
    helper(root,prev);
 	return root2;
  
}
```
