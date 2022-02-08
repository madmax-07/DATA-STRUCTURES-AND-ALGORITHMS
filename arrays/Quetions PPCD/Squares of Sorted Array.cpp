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
