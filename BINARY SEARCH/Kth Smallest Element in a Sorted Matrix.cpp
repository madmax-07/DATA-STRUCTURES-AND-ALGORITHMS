/*solution approach 
For an element to the Kth smallest element there should be atleast k no of elements that are less than or equal to it so 
Step 1: what we do is find the minimum in the matrix and the maximum (since the elements in the matrix will lie in that range only) We will get a montonic search space 
Step 2: Now we will find the mid and find the number of elements that are less than or equal to it (using upper_bound() )
 (a) If we find that the count of element is < K then the mid needs to be increased (since there arent k elements that are smaller and less than mid)
 (b) If count>k them mid needs to be descresed
 (c) If count==k then the mid is a possible ans we will decrease the mid (consider the test case of the question given we get 14 for which count==k but thats not the ans)

*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    int r=matrix.size();
    int c=matrix[0].size();
    int low=matrix[0][0];
    int high=matrix[r-1][c-1];
        int ans;
   
    while(low<=high)
    {
         int mid=low+(high-low)/2;
         int count=0;
        for(int i=0;i<r;i++)
        { auto it=upper_bound(matrix[i].begin(),matrix[i].end(),mid);
         count+= it-matrix[i].begin();
        }
      
        
     if(count>=k)
     {      ans=mid;
            high=mid-1;
     }
     else
        {   
            low=mid+1;
        }
    }
        return ans;
    }
};
//Tc: nlogn *ub
//sc:O(1)
