class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>&l2) {
        int i=0,j=0;
        vector<vector<int>>ans;
       while(i<l1.size() and j<l2.size()){
           if(l1[i][0]<=l2[j][0] and l2[j][0]<=l1[i][1]){
               int s=l2[j][0];
               int e=min(l1[i][1],l2[j][1]);
               // vector<int>v;
               // v.push_bcak()
               ans.push_back({s,e});
             }
           else if(l1[i][0]>=l2[j][0] and l1[i][0]<=l2[j][1]){
               int s=l1[i][0];
               int e=min(l1[i][1],l2[j][1]);
               ans.push_back({s,e});
           }
               if(l1[i][1]>l2[j][1])
                   j++;
               else 
                   i++;
             }
        return ans;
       } 

};
