# Graphs 
## Representation
  *Adjacency List
  ```C++
  Class Graph{
    map<int,vector<int>>mp;
    Public:
    void add_edge(int x,int y,bool bidr,int wt)
    { mp[x].push_back(y);
        if(bidr)
      mp[y].push_back(x);    
    }
    void print_list(){
    for(auto x:mp){
    cout<<x.first<<":";
    for(auto it:x.second)
    cout<<it<<" ";
   }
 };
  ```
## TRAVERSAL
  
* Two Manin Trversals are possible in graphs 
 * BFS - Breadth First Traversal 
    * This approach involves visiting all the neighbours of a particular node(Lets say src) and the  visisting further node until all nodes are visistied
   ```C++
   // map<int,vector>graph;
   bfs(int src){
   map<int,int>visted;
   queue<int>q;
   q.push(src);
   visted[src]=1;
   while(!q.empty()){
    int temp=q.front();
    q.pop();
    for(auto x:graph[temp]){
      if(!visted[x]){
      q.push(x)
      visted[x]=1;
      }
    }
    }
      
 * DFS - Depth First Traversal 
