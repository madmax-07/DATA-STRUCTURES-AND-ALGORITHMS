```C++
class Solution{
  public:
    int ans=-1;
    /*You are required to complete this method*/
    int helper(Node*root,int level){
    if(root==NULL)
        return 1;
    if(root->left==NULL and root->right==NULL){
        if( ans==-1)
         { ans=level;
           return 1;
         }
        else if(ans!=-1 and level!=ans)
          return 0;
        else return 1;
    }
         return (helper(root->left,level+1)and helper(root->right,level+1));
        
            
    }
    bool check(Node *root)
    { if(root==NULL)
        return 1;
    return helper(root,0);
       
        //Your code here
    }
};
```
