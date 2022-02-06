/*What is Hamiltonian path?
  Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. 
  A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in the graph) from the last vertex to the first vertex of the
  Hamiltonian Path.
*/
  bool dfs(map<int,vector<int>>graph,int src,int orsc,map<int,int>&visted,vector<int>path){
    //The base case will involve if the size of the path == total vertices then hum sare vertices uss path se ek baar visit kar chuke h
        if(path.size()==map.size()-1){
            bool ham_path=false;
//the following condition is being checked for hamiltonian path :i.e to see if we have an edge form last vertex to first vertex.Like agar voh uke connecting nodes mai aya toh haan theek h  
            for(auto x:graph[src]){
                if(x==orsc)
                {ham_oath=true;
                    return ham_path;
            }   }
        }
        visted[src]=1;
        path.push_back(src);
        for(auto x:graph[src]){
            if(!visted[x])
                dfs(graph,x,orsc,visted,path)
        }
    visted[src]=0;
    }
    hamiltanian_cycle(map<int,vector<int>>graph){
        //base case
        map<int,int>visted;
        vector<int>path;
        return dfs(graph,src,visted,path);
     }
};
