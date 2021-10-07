class Solution
{
public:
  //The REVERSAL ALGORITHM TO ROTATE AN ARRAY 
  /*
  189. Rotate Array
Medium

6178

1039

Add to List

Share
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
  */
  void rotate(vector<int> &a, int k)
    {
        int n = a.size();
        if (k >= n)
        {
            k = k % n;
        }
        int index = n - k;
        //rotate array A
        int i = 0, j = index - 1;
        while (i < j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
        //rotate array B
        i = index, j = n - 1;
        while (i < j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
        //rotate array A and B

        i = 0, j = n - 1;
        while (i < j)
        {
            swap(a[i], a[j]);

            i++, j--;
        }
    }
};
