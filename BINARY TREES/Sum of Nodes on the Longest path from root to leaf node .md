```C++
class Solution
{
public:
int lps=0;
int lpsum=0;
    void helper(Node*root,int ps,int psum){
        if(root==NULL)
         return;
         psum+=root->data;
        
         if(!root->left and !root->right){
             if(ps==lps){
                 lpsum=max(lpsum,psum);
                 lps=ps;
             }
             else if(ps>lps)
             {  lpsum=psum;
                lps=ps;
             }
             
             return ;
         }
     
        helper(root->left,ps+1,psum);
        helper(root->right,ps+1,psum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {   if(root==NULL)
            return 0;
         helper(root,1,0);
         return lpsum;
        //code here
    }
};
```
