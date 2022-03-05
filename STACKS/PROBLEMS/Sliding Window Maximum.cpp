//This method uses the concept of next greater element 
class Solution {
public:
    void NGE(vector<int>&nums,vector<int>&nge){
        stack<pair<int,int>>s;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and s.top().first<nums[i])
                s.pop();
            if(s.empty()){
                nge[i]=n;
            }
            else if(!s.empty()){
                nge[i]=s.top().second;
            }
            s.push({nums[i],i});
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>max(n-k+1);
        vector<int>nge(n);//stores the index for next greater elemnt
        NGE(nums,nge);
        int i=0,j=0;
        while(i+k-1<n){
            if(j<i)j=i;
            int w=i+k;
            while(nge[j]<w)
                j=nge[j];
            max[i]=nums[j];
            i++;        
        }
        return max;
        
        
    }
};
