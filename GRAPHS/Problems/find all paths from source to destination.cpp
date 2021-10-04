class Solution {
public:
    vector<vector<int>>v;
    map<int,vector<int>>mp;
    void make_list(vector<vector<int>>& graph){
        for(int i=0;i<graph.size();i++){
            for(auto x:graph[i])
            mp[i].push_back(x);
            }
        }
    void find_allpath(int src,int dest,bool *visted,vector<int>paths){
        paths.push_back(src);
        if(src== dest)
        {  v.push_back(paths);
         return;
        }
        visted[src]=true;
        for(auto it:mp[src]){
            if(!visted[it]){
                find_allpath(it,dest,visted,paths);
            }
        }
        visted[src]=false;
        }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        make_list(graph);
        vector<int>paths;
        bool visted[graph.size()];
        for(int i=0;i<graph.size();i++){
            visted[i]=false;
        }
        find_allpath(0,graph.size()-1,visted,paths);
        return v;
    }
};
