/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
  */
class Solution {
public:
    void get_subset(vector<int>&nums,vector<int>&ans,vector<vector<int>>&result,int i){
        if(i==nums.size())
        { result.push_back(ans);
          return;
        }
        //include the no
        ans.push_back(nums[i]);
        get_subset(nums,ans,result,i+1);
        //dont include
        ans.pop_back();
        get_subset(nums,ans,result,i+1);
      
    }
    vector<vector<int>> subsets(vector<int>& nums) {
             vector<int>ans;
             vector<vector<int>>result;
             get_subset(nums,ans,result,0);
            return result;
        
    }
};
