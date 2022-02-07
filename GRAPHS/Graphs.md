# Graphs 
## Representation
  ### Adjacency List
  ```C++
Class Graph
{
  map<int, vector<int>> mp;
Public:
  void add_edge(int x, int y, bool bidr, int wt)
  {
    mp[x].push_back(y);
    if (bidr)
      mp[y].push_back(x);
  }
  void print_list()
  {
    for (auto x : mp)
    {
      cout << x.first << ":";
      for (auto it : x.second)
        cout << it << " ";
    }
  };
  ```
## TRAVERSAL
  
* Two Main Trversals are possible in graphs 
 * BFS - Breadth First Traversal 
    * This approach involves visiting all the neighbours of a particular node(Lets say src) and the  visisting further node until all nodes are visistied
```C++
  // map<int,vector>graph;
bfs(int src)
{
  map<int, int> visted;
  queue<int> q;
  q.push(src);
  visted[src] = 1;
  while (!q.empty())
  {
    int temp = q.front();
    q.pop();
    for (auto x : graph[temp])
    {
      if (!visted[x])
      {
        q.push(x)
            visted[x] = 1;
      }
    }
  }
 ```
  * Time Complexity Analysis of BFS O(V+E) V= no of vertices; E=no of edges
      V X (O(1) + E + O(1))= V + V*E + V= 2V + E =O(V+E)
 
 * DFS - Depth First Traversal 
  * The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each 
 branch before backtracking.
``` C++
  dfs_helper(int src, map<int, int> &visted)
{
  cout << src << " ";
  visted[src] = 1;
  for (auto x : graph[src])
  {
    if (!visted[x])
    {
      dfs_helper(src, visted)
    }
  }
}
dfs(int src)
{
  map<int, int> visted;
  for (auto x : graph)
    visted[x.first] = false;
  dfs_helper(src, visted);
}
```
* Time Complexity Analysis =O(N)
