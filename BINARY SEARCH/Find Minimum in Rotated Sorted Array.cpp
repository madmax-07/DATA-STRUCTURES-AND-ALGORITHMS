Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
  
//solution 
  class Solution {
public:
    int helper(vector<int>&a,int l,int h){
      //eg:[1]
        if(l==h)
        return a[l];
      //eg:[1,2]
        if(l>h)
        return a[0];
      //
       else{ 
        int m=(l+h)/2;
         //the condition l<m is when m=0 then we cant check for a[m-1]==a[-1]-->wrong and will cause overflow
         if(l<m and a[m-1]>a[m])
            return a[m];
         //the condition l>m is when m=n-1 then we cant check for a[m+1]==a[n]-->wrong and will cause overflow
        if(h>m and a[m+1]<a[m])
            return a[m+1];
         if(a[h]>a[m])
            return helper(a,l,m-1);
        
        return helper(a,m+1,h);
       }
                
        
        
    }
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        return helper(nums,l,h);
        
    }
};
