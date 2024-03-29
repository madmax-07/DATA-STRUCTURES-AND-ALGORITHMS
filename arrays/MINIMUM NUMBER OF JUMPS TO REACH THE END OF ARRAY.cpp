/*
45. Jump Game II
Medium

5960

226

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000


*/
class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
        if(n==1)
            return 0;
        else if(a[0]==0)
            return -1;
        else{
            int maxreach=a[0];
            int jump=1;
            int step=a[0];
            for(int i=1;i<n;i++){
                if(i==n-1)
                    return jump; //reched teh end of the array
                maxreach=max(maxreach,a[i]+i);
                step--;
                if(step==0){
                    jump++;
                    if(i>=maxreach)
                        return -1;
                    step=maxreach-i;}}
                    return jump;}
                }
            
};
