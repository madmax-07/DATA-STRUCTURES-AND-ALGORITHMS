class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        vector<int>ans(a.size());
        //precompute left prduct
        ans[0]=1;
        int lp=a[0];
        for(int i=1;i<a.size();i++){
            ans[i]=lp;
            lp*=a[i];
        }
        int rp=1;
        for(int i=a.size()-1;i>=0;i--){
            ans[i]=ans[i]*rp;
            rp=rp*a[i];
      }
        return ans;
        
    }
};
//TC:O(n)
//SC:O(n)
