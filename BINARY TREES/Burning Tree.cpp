class Solution {
  public:
   int maxtime=0;
 void cal_Kdown(Node*root,int time){
      if(root==NULL)
       return;
       maxtime=max(maxtime,time);
       cal_Kdown(root->left,time+1);
       cal_Kdown(root->right,time+1);

 }
int help(Node*root,int target){
    if(root==NULL)
     return -1;
     if(root->data==target){
         cal_Kdown(root,0);
         return 0;
     }
     int lh=help(root->left,target);
     if(lh!=-1){
         maxtime=max(maxtime,lh+1);
         cal_Kdown(root->right,lh+2);
         return lh+1;
     }
     int rh=help(root->right,target);
         if(rh!=-1){
             maxtime=max(maxtime,rh+1);
             cal_Kdown(root->left,rh+2);
             return rh+1;
         }
         return -1;
     }
    int minTime(Node* root, int target) 
    { help(root,target);
      return maxtime;
        // Your code goes here
    }
};
