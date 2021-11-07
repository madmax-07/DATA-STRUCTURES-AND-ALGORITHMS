class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int el1=-1;
        int el2=-1;
       
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el1)
                count1++;
            
            else if(nums[i]==el2)
                count2++;
            
            else if(count1==0)
            {el1=nums[i];
             count1=1;
            }
            else if(count2==0)
            {
                el2=nums[i];
                count2=1;
            }
            else 
            {count1--;
             count2--;
            }   
            
        }
     vector<int>ans;
     count1=count2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==el1)
        count1++;
        
        else if(nums[i]==el2)
            count2++;
    }
        if(count1> nums.size()/3)
            ans.push_back(el1);
        if(count2>nums.size()/3)
            ans.push_back(el2);
    
    return ans;
}
};
