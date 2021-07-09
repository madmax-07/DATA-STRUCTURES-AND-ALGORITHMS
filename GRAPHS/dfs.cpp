#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
    map<T, list<T>> mp;

public:
    void add_edge(T x, T y, bool bidr)
    {
        mp[x].push_back(y);
        if (bidr)
        {
            mp[y].push_back(x);
        }
    }
    void print()
    {
        for (auto x : mp)
        {
            cout << x.first << ":";
            for (auto i : x.second)
                cout << i << ",";
            cout << endl;
        }
    }
    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout << src <<endl;
        visited[src] = true;
        for (auto i : mp[src])
        {
            if (!visited[i])
            {
                dfs_helper(i, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        //mark all the nodes as visisted
        for (auto i : mp)
        {
            T node = i.first;
            visited[node] = false;
        }
        dfs_helper(src, visited);
    }
};
int main()
{
    graph<string> g;

    g.add_edge("A", "B", true);
    g.add_edge("A", "D", false);
    g.add_edge("A", "C", true);
    g.add_edge("B", "D", true);
    g.add_edge("C", "D", true);
    g.print(); /*the nodes will not be printed in lexographical order since we are using an unordered map
                TO PRINT IN LEXOGRAPHICAL ORDER USE MAP
            
                */
    g.dfs("A");
    cout << endl;
}