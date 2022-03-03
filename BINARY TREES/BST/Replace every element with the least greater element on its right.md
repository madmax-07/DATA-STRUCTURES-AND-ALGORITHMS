
```C++
class Node{
    public:
    int val;
    Node*left;
    Node*right;
   Node(int x){
   val=x;
   left=NULL;
   right=NULL;
  }
};
Node*insert(Node*root,int x,int& succ){
 if(root==NULL){
     Node*temp=new Node(x);
     return temp;
 }
    if(x<root->val){
        root->left=insert(root->left,x,succ);
        if(succ==-1)
            succ=root->val;
    }
    else if(x>=root->val){
        root->right=insert(root->right,x,succ);
    }
    return root;
}
vector<int> leastGreaterElement(vector<int> &arr) 
{   int n=arr.size()-1;
 Node*root=NULL;
 if(arr.size()==0){
     return arr;
 }
  for(int i=n;i>=0;i--){
      int succ=-1;
     root=insert(root,arr[i],succ);
      arr[i]=succ;
  }
 return arr;
    //    Write your code here

}
```
