//recursive solution 
int fib(n){
  if(n==0||n==1)
    return n;
  //recursive case
  return fib(n-1)+fib(n-2);
  }
/*
time complexity:O(2^n)
space complexity :O(n)->stack space
*/
//DP solution 
//TOP DOWN APPROACH - RECURSION + MEMOIZATION 
class Solution {
public:
    int fibo(int n ,int*dp){
        //base case
        if(n==0 ||n==1)
            return n;
        //look up-Check if the ans already exist 
        if(dp[n]!=0)
            return dp[n];
        //recur case
    int ans=fibo(n-1,dp)+fibo(n-2,dp);
    dp[n]=ans; //save the ans for future use
    return dp[n]
    }
    int fib(int n) {
        int dp[31]={0};
        return fibo(n,dp);
        
    }
 //time complexity:O(n)
 //space cpmplexiy :O(n)
};
//BOTTOM-UP APPROACH- This is basically known as Dp approach 
int fib(int n int*dp)
{
  dp[0]=0;
  dp[1]=1;
for(int i=2;i<n;i++)
{ dp[i]=dp[i-1]+dp[i-2];
}
return dp[n];
}

