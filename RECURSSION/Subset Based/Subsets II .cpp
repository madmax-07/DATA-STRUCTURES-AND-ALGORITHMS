
/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/
class Solution {
public:
    void helper(vector<int>&nums,int n,vector<vector<int>>&ans,vector<int>&v,int i){
        if(i==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(nums,n,ans,v,i+1);
        int id=i;
        while(i<n and nums[i]==nums[id])
            i++;
        v.pop_back();
        helper(nums,n,ans,v,i);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        int n=nums.size();
        helper(nums,n,ans,v,0);
        return ans;
    }
    
};
