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
class Solution {
public:
    int fibo(int n ,int*dp){
        //base case
        if(n==0 ||n==1)
            return n;
        //look up
        if(dp[n]!=0)
            return dp[n];
        //recur case
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    }
    int fib(int n) {
        int dp[31]={0};
        return fibo(n,dp);
        
    }
 //time complexity:O(n)
 //space cpmplexiy :O(n)
};
