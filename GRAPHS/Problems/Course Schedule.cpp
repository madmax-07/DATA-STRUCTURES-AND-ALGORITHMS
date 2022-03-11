class Solution {
public:
    
    int  detect_cycle(int src,map<int,vector<int>>&mp,map<int,int>&visted,map<int,int>&inpath){
        visted[src]=1;
        inpath[src]=1;
        for(auto it:mp[src])
        { if(!visted[it])
          {
            bool is_cycleP=detect_cycle(it,mp,visted,inpath);
            if(is_cycleP)
                return 1;
           }
          else if(visted[it] and inpath[it])
            return 1;
        }
        inpath[src]=0;
        return 0;
    }
    bool canFinish(int nc, vector<vector<int>>& prereq) {
    //in this question what we have to technicaly do is check is to detect cycle in graph 
        map<int,vector<int> >mp;
        for(int i=0;i<prereq.size();i++){
            mp[prereq[i][1]].push_back(prereq[i][0]);
        }
         map<int,int>visted;
         map<int,int>inpath;
        for(auto x:mp)
            visted[x.first]=0;
        for(auto x:mp){
            if(!visted[x.first])
            { bool ans=detect_cycle(x.first,mp,visted,inpath);
              if(ans)//cyclepresent
                  return false;
            }
        }
        return true;
    }
};
