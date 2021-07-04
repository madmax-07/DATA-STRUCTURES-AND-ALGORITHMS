#include <bits/stdc++.h>
using namespace std;
class graph
{
    map<string, list<string>> mp;

public:
    void add_edge(string x, string y, bool bidr)
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
    void bfs(string src)
    {
        queue<string> q; 
        map<string, bool> visited;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            string s = q.front();
            q.pop();
            cout << s << "->";
            for (auto i : mp[s])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};
int main()
{
    graph g;

    g.add_edge("A", "B", true);
    g.add_edge("A", "D", false);
    g.add_edge("A", "C", true);
    g.add_edge("B", "D", true);
    g.add_edge("C", "D", true);
    g.print(); /*the nodes will not be printed in lexographical order since we are using an unordered map
                TO PRINT IN LEXOGRAPHICAL ORDER USE MAP
            
                */
cout<<endl;
cout<<"BFS traversal of graph"<<endl;
g.bfs("B");


}
