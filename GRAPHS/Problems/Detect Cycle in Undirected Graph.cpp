bool Bfs_detectCycle(int src,map<int,int>&visted,map<int,int>&parent,map<int,vector<int>>&mp){
    visted[src]=1;
    parent[src]=-1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto it:mp[temp]){
            if(!visted[it])
            { visted[it]=1;
              parent[it]=temp;
              q.push(it);
            }
            else if(visted[it] and parent[temp]!=it)
              return true;
        }
        return false;
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
   //step 1 make graph
    map<int,vector<int>>mp;
    for(int i=0;i<B.size();i++){
        mp[B[i][0]].push_back(B[i][1]);
        mp[B[i][1]].push_back(B[i][0]);
    }
   map<int,int>visted;
   map<int,int>parent;
   for(auto it:mp){
       visted[it.first]=0;
       parent[it.first]=it.first;
   }
   for(auto x :mp){
       if(!visted[x.first]){
           bool is_cyclic=Bfs_detectCycle(x.first,visted,parent,mp);
           if(is_cyclic)
            return 1;
       }
   }
   return 0;
}
