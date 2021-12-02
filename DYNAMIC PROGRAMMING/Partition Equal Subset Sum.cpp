class Solution {
public:
    int help(vector<int>& nums,int n,int sum,int**dp){
        if(n==0 and sum>0)
            return 0;
        if(n==0 and sum==0||sum==0)
            return 1;
    if(dp[n][sum]!=-1)
      return dp[n][sum];
     
    if(nums[n-1]<=sum){
        dp[n][sum]=(help(nums,n-1,sum-nums[n-1],dp)|| help(nums,n-1,sum,dp));
        return dp[n][sum];
    }
    
    dp[n][sum]=help(nums,n-1,sum,dp);
    return dp[n][sum];
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        int n=nums.size();
         int** dp;
    dp = new int*[n+1];
 
    // loop to create the table dynamically
    for (int i = 0; i <=n; i++)
        dp[i] = new int[sum/2+1];
        for(int i=0;i<=n;i++)
        for(int j=0;j<=sum/2;j++)
         dp[i][j]=-1;
        if(help(nums,nums.size(),sum/2,dp))
            return true;
        else 
            return false;
        
    }
};
