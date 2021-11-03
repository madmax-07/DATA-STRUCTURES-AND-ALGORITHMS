class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i=-1;
        int j=0;
        while(j<nums.size()){
            while(j<nums.size() and nums[j]==0)
            {   j++;
             }
            if(j<nums.size())
            {   nums[i+1]=nums[j];
                j++;
                i++;
            }
            
    }
    i++;
    while(i<nums.size())
    nums[i++]=0;
    }
};
