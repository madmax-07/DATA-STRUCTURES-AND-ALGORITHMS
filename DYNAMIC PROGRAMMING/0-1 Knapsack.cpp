//This is recursive + memoization approach  
int help(vector<int> &val, vector<int> &wght,int cap,int n,int **dp){
    if(n==0||cap==0)
    return 0;
    if(dp[n][cap]!=-1)
    return dp[n][cap];
    if(wght[n-1]<=cap)
    { dp[n][cap]=max((help(val,wght,cap-wght[n-1],n-1,dp)+val[n-1]),help(val,wght,cap,n-1,dp));
        return dp[n][cap];
    }
    else 
    dp[n][cap]=help(val,wght,cap,n-1,dp);
    return dp[n][cap];
    
    }
int Solution::solve(vector<int> &val, vector<int> &wght, int cap) {
    int n=val.size();
    
     
     
  int** dp;
    dp = new int*[n+1];
 
    // loop to create the table dynamically
    for (int i = 0; i <=n; i++)
        dp[i] = new int[ cap + 1];
 
    // loop to initially filled the
    // table with -1
    for (int i = 0; i <=n; i++)
        for (int j = 0; j <=cap; j++)
            dp[i][j] = -1;
    return help(val,wght,cap,n,dp);
}
//Time Complexity=O(n*n)

