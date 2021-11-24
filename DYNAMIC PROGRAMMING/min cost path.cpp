class Solution {
public:
    int dp[201][201];
    int help(vector<vector<int>>& grid,int r,int c,int i,int j){
        if(i>=r or j>=c) 
            return INT_MAX;
        if(i==r-1 and j==c-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int op1=help(grid,r,c,i,j+1);
        int op2=help(grid,r,c,i+1,j);
        dp[i][j]=min(op1,op2)+grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return help(grid,r,c,0,0);
        
        
    }
};
//time complexity :O(n X m)
//space complexity;O(n X m)
