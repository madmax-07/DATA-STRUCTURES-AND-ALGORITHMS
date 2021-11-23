/*
Minimum Operations 
Easy Accuracy: 51.45% Submissions: 15772 Points: 2
Given a number N. Find the minimum number of operations required to reach N starting from 0. You have 2 operations available:

Double the number
Add one to the number

Example 1:

Input:
N = 8
Output: 4
Explanation: 0 + 1 = 1, 1 + 1 = 2,
2 * 2 = 4, 4 * 2 = 8

â€‹Example 2:

Input: 
N = 7
Output: 5
Explanation: 0 + 1 = 1, 1 + 1 = 2,
1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7

*/
class Solution
{
  public:
   int solve(int n,int num,int *dp){
       if(n==num)
       return 0;
       if(dp[n]!=0)
       return dp[n];
       int ans1=INT_MAX;
       int ans2=INT_MAX;
       if(n>0 and n*2<=num)
        ans1=solve(n*2,num,dp);
       
       if(n+1<=num)
         ans2=solve(n+1,num,dp);
        return dp[n]=min(ans1,ans2)+1;
    }
    int minOperation(int n)
    { int dp[1000001]={0};
        //code here.
        solve(0,n,dp);
    }
};
