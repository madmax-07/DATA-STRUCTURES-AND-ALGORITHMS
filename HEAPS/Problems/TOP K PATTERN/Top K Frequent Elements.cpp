/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //step 1: create a frequency hash map to count the frequency of every elemnt in the array
    unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
             mp[nums[i]]++;
        }
//step 2: push the pair (freq,elem) into the hash-map which will store the pairs according to the freq 
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        int cnt=1;
//step 3:top k freq elements are poped from the queue 
        while(cnt<=k and !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return ans;
        
    }
};
