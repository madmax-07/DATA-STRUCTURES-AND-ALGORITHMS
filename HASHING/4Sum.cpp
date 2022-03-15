class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>>ans;
        while(i<=n-4){
            int j=i+1;
            while(j<=n-3){
                int tar=target-(nums[i]+nums[j]);
                int l=j+1;
                int m=n-1;
                while(l<m){
                    if(nums[l]+nums[m]==tar){
                        ans.push_back({nums[i],nums[j],nums[l],nums[m]});
                        int l1=l+1;
                        while(l1<m and nums[l1]==nums[l])
                            l1++;
                        l=l1;
                        int m1=m-1;
                        while(m1>l and nums[m1]==nums[m])
                            m1--;
                        m=m1;
                    }
                    else if(nums[l]+nums[m]<tar){
                        
                            l++;
                    }
                    else if(nums[l]+nums[m]>tar)
                    {
                        m--;
                    }
                }
                int j1=j+1;
                while(j1<=n-3 and nums[j]==nums[j1])
                    j1++;
                j=j1;
                }
            int i1=i+1;
            while(i1<=n-4 and nums[i]==nums[i1])
                i1++;
            i=i1;
        }
        return ans;
        
        
    }
};
