class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0,j=0;
        while(i<m and j<n){
            if(nums1[i]<=nums2[j])
                i++;
            else if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                 i++;
                //put the elemt in arr2 at right position
                for(int k=j;k<nums2.size()-1;k++){
                    if(nums2[k]>nums2[k+1])
                        swap(nums2[k],nums2[k+1]);
                }
            }
        }
        
        for(;i<nums1.size() and j<nums2.size();i++)
            nums1[i]=nums2[j++];
            }
};
