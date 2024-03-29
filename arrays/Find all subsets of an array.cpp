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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int n=pow(2,nums.size()); //there will be 2^n elemnts in the power set
        for(int i=0;i<n;i++){ //we will iterate from 1 to 2^n elements 
            vector<int>v;
            int temp=i;
            for(int j=nums.size()-1;j>=0;j--){ /*for each i[ ranging from 0 to 2^n-1] we will get the binary bits */
                                              
                int r=temp%2;
                temp=temp/2;
                if(r!=0)
                v.push_back(nums[j]);
            }
            reverse(v.begin(),v.end());
            ans.push_back(v);
            v.clear();
        }
        return ans;
    
        
    }
};
//tc:O(n*2^n)
//SC:O(1)
