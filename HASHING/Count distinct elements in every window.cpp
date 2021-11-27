class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        vector<int>ans;
        map<int,int>mp;
        int i;
        for( i=0;i<k;i++)
            mp[a[i]]++;
        
        ans.push_back(mp.size());
        for(;i<n;i++){
            mp[a[i-k]]--;
            if(mp[a[i-k]]==0)
             mp.erase(a[i-k]);
            mp[a[i]]++;
            ans.push_back(mp.size());
        }
        return ans;

    }
        
};
//Tc:O(n)
//sc=O(k)--The no of distinct elemnts in every window which in worst case can be k 
