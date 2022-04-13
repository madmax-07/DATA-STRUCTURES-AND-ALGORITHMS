class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
         int flag=0;
        for(int i=0;i<arr.size() and n>0;i++){
         if(arr[i]==1){
             flag=1;
         }
         else if(flag and arr[i]==0){
             flag=0;
         }
         else if(!flag)
         {  if(i==arr.size()-1)
            n--;           
           else if(i<arr.size()-1 and arr[i]==0 and arr[i+1]!=1)
               n--;
            flag=1; 
        }
        }
        if(n==0)
            return true;
        else return false;
    }
};
