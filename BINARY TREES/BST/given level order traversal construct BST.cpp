//https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1
//Function to construct the BST from its given level order traversal.
/*METHOD 1:CONSTRUCT A BST as you are adding elements in a bst 
 TC:O(n^2) its like we are inserting n nodes in a bst 
 SC:O(nh)
*/
void build(int a,Node*&root){
    if(root==NULL)
    { root=new Node(a);
        return ;
    }
    if(a<root->data)
    build(a,root->left);
    
    else if(a>root->data)
    build(a,root->right);

}
Node* constructBst(int a[], int n)
{
    // Code here
    Node*root=NULL;
    if(n==0)
    return NULL;
    for(int i=0;i<n;i++){
        build(a[i],root);
    }
    return root;
}
//----------------END OF METHOD 2--------------------------------------------------------------------------------------
//METHOD 2

