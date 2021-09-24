/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/
class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int>v;
    void build(Node*root,vector<int>v,int &i){
        if(root==NULL)
        return ;
        build(root->left,v,i);
        root->data=v[i++];
        build(root->right,v,i);
    }
    void preorder(Node*root,vector<int>&v){
        if(root==NULL)
        return;
        v.push_back(root->data);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        v.resize(0);
        preorder(root,v);//O(logn)
        sort(v.begin(),v.end());//O(nlogn)
        int i=0;
         build(root,v,i); //O(logn)
         return root;
    }
};
//TC-O(nlogn)
//SC-O(h) recursive stack space 
