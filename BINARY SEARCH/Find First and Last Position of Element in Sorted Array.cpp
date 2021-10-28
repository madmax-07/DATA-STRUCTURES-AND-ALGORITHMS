class Solution {
public:
    int fo_search(vector<int>&a,int l,int h,int target){
        if(l<=h){
            int m=l+(h-l)/2;
            if(a[m]==target)
            { int fo=m;
            int id=fo_search(a,l,m-1,target);
            if(id==-1)
                return fo;
            else return id;
            }
            else if(target<a[m])
            return fo_search(a,l,m-1,target);
            else return fo_search(a,m+1,h,target);
        }
        return -1;
    }
int lo_search(vector<int>&a,int l,int h,int target){
        if(l<=h){
            int m=l+(h-l)/2;
            if(a[m]==target)
            { int lo=m;
             int id=lo_search(a,m+1,h,target);
             if(id==-1)
                 return lo;
             else return id;
            }
            else if(a[m]>target)
                return lo_search(a,l,m-1,target);
            
            else return lo_search(a,m+1,h,target);
        }
        return -1;
        }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int fo=fo_search(nums,0,nums.size()-1,target);
        int lo=lo_search(nums,0,nums.size()-1,target);
        vector<int>ans;
        ans.push_back(fo);
        ans.push_back(lo);
        return ans;
        }
};
