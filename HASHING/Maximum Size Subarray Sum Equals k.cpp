class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        int n=nums.size();
        int sum=0;
        map<int,int>mp;
        mp[0]=-1;
        int maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int y=sum-k;
            if(mp.find(y)!=mp.end()){
                int len=(i-mp[y]);
                // cout<<len<<"@";
                maxlen=max(maxlen,len);
            }
            if(mp.find(sum)!=mp.end())
            mp[sum]=min(mp[sum],i);
            else 
            mp[sum]=i;
        }
        if(maxlen==INT_MIN)
         return 0;
         
        return maxlen;
    }
};
