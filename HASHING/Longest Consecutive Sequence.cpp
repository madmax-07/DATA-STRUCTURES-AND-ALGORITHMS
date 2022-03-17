class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool>mp;
//STEP 1 Intialise all the elements in the array as true i.e they can be start of SS 
        for(int i=0;i<nums.size();i++)
          mp[nums[i]]=true;
//STEP 2 Initialise elements which can't be SS as false 
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)!=mp.end())
                mp[nums[i]]=false;
        }
//STEP 3: Iterate the loop for those elemnts which can be the start of SS
        int ans=0; //smallest SS
        for(auto it:mp){
             int n=it.first;
            if(it.second){
                int cnt=1;
                //Check for the element ki usse ketne bade consecutive ss ban rahi h
                while(mp.find(n+1)!=mp.end()){
                    n=n+1;
                    cnt++;
                }
                ans=max(cnt,ans);
            }
        }
        return ans;
    }
};
