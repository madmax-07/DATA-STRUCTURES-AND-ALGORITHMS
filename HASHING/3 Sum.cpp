class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        int i=0;
        while(i<=n-3){
            int x=nums[i];
            int j=i+1,k=n-1;
            int target=-x;
            vector<int>v;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]); 
                    ans.push_back(v);
                    v.clear();
                    int j1=j+1;
                    while(j1<k and nums[j1]==nums[j])
                        j1++;
                    j=j1;
                    int k1=k-1;
                    while(k1>j and nums[k1]==nums[k])
                        k1--;
                    k=k1;
                }
                else if(nums[j]+nums[k]<target){
                    // int j1=j+1;
                    // while(j1<k and nums[j1]==nums[j])
                    //     j1++;
                    j++;
                }
                else if( nums[j]+nums[k]>target){
                // {  int k1=k-1;
                //     while(k1>j and nums[k1]==nums[k])
                //         k1--;
                    k--;
                }
            }
            int id=i+1;
            while(id<=n-3 and nums[i]==nums[id])
                id++;
            i=id;
        }
        return ans;
    }
};
