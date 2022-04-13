class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int j=s.size()-1;
        int i=g.size()-1;
        while(j>=0 and i>=0){
            if(s[j]>=g[i]){
                j--;
                ans++;
            }
            i--;
        }
        return ans;
      
            
    }
};
