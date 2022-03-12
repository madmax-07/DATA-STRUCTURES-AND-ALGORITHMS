class Solution {
public:
   
bool detect_cycle(int src, map<int, int> &visted, map<int, int> &in_path,vector<int>&ordering,map<int, vector<int>> &mp)
    {
        visted[src] = 1;
        in_path[src] = 1;
        for (auto it : mp[src])
        {
            if (!visted[it])
            {
                bool is_cyclic = detect_cycle(it, visted, in_path,ordering ,mp);
                if (is_cyclic)
                    return true;
            }
            else if (visted[it] and in_path[it])
                return true;
        }
       in_path[src]=0;
       ordering.push_back(src);
       return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
    vector<int> ordering;
    if (pre.size() == 0)
    {
        for (int i = 0; i < numCourses; i++)
            ordering.push_back(i);

        return ordering;
    }
    // Step 1 : Make graph
    map<int, vector<int>> mp;
    for (int i = 0; i < pre.size(); i++)
    {
        mp[pre[i][1]].push_back(pre[i][0]);
    }
    map<int, int> visted;
    for (auto x : mp)
    {
        visted[x.first] = 0;
    }
    map<int, int> in_path;
    // its is impossible to do all courses if there is cycle te graph :Detect CYCLE
    // for (auto it : mp)
    // {
    //     if (!visted[it.first])
    //     {
    //         bool is_cyclic = detect_cycle(it.first, visted, in_path, mp);
    //         if (is_cyclic)
    //             return ordering;
    //     }
    // }
    // do a toposort

    // for (auto x : mp)
    //   visted[x.first] = 0;
    
    for (auto it : mp)
    {
        if (!visted[it.first])
        {bool cyclic= detect_cycle(it.first, visted,in_path,ordering,mp);
          if(cyclic){
              ordering.clear();
              return ordering;
          }
    }
    }
     for(int i=0;i<numCourses;i++){
         if(!visted[i])
             ordering.push_back(i);
     }
    reverse(ordering.begin(), ordering.end());
    return ordering;
}
};
