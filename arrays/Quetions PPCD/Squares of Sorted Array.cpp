/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
         int ni=0,pi=0;
        while(ni<nums.size() and nums[ni]<0)
            ni++;
        pi=ni;
        ni-=1;
        while(ni>=0 and pi<nums.size()){
            if(abs(nums[ni])<=nums[pi]){
                ans.push_back(nums[ni]*nums[ni]);
                ni--;
            }
            else 
            {ans.push_back(nums[pi]*nums[pi]);
            pi++;
            }
        }
        while(ni>=0){
           ans.push_back(nums[ni]*nums[ni]);
            ni--;
        }
        while(pi<nums.size())
        {
            ans.push_back(nums[pi]*nums[pi]);
            pi++;
        }
            
        return ans;
    }
};
//The above approach has a TC =O(n) but a more elegant solution using just on one loop is below 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
         int low=0,high=nums.size()-1;
         int idx=high;
        while(low<=high){
            if(abs(nums[low])>=abs(nums[high])){
                ans[idx]=nums[low]*nums[low];
                low++;
            }
            else{
                ans[idx]=nums[high]*nums[high];
                high--;
            }
            idx--;
        }
        return ans;
    }
};
