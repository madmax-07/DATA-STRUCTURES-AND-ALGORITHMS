class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        map<int,int>mp;
        int maxlen=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)
            maxlen=i+1;
            else if(mp.find(sum-k)!=mp.end()){
                maxlen=max(i-mp[sum-k],maxlen);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxlen;

    }
};
