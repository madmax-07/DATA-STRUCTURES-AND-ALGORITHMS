class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(auto it:points){
            int d=it[0]*it[0] + it[1]*it[1];
            maxh.push({d,{it[0],it[1]}});
            if(maxh.size()>k)
                maxh.pop();
            }
        vector<vector<int>>ans;
    while(!maxh.empty()){
        vector<int>r;
        pair<int,pair<int,int>>p=maxh.top();
        maxh.pop();
        r.push_back(p.second.first);
        r.push_back(p.second.second);
        ans.push_back(r);
        r.clear();
    }
        return ans;
    }
    
};
