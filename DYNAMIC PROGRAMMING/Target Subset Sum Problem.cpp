/*
Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 10
*/
class Solution{   
public:
int help(int n,int*arr,int sum,int **dp){
    //base case 
    if(n==0 and sum>0)
     return 0;
    if(n==0 and sum==0 || sum==0)
     return 1;
     
     if(dp[n][sum]!=-1)
      return dp[n][sum];
     
    if(arr[n-1]<=sum){
        dp[n][sum]=(help(n-1,arr,sum-arr[n-1],dp)|| help(n-1,arr,sum,dp));
        return dp[n][sum];
    }
    
    dp[n][sum]=help(n-1,arr,sum,dp);
    return dp[n][sum];
}
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        int** dp;
    dp = new int*[n+1];
 
    // loop to create the table dynamically
    for (int i = 0; i <=n; i++)
        dp[i] = new int[sum+1];
        for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)
         dp[i][j]=-1;
        return help(n,arr,sum,dp);
    }
        
};
