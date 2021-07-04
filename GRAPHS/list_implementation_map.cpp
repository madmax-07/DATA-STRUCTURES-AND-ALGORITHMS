#include <bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<string, list<pair<string, int>>> mp;

public:
    void add_edge(string x, string  y, bool bidr, int wt)
    {
        mp[x].push_back(make_pair(y, wt));
        if (bidr)
        {
            mp[y].push_back(make_pair(x, wt));
        }
    }
    void print()
    {
        for (auto i : mp)
        {                                                                  /*A->(B,20),(C,10),(D,50)
                                                                             B->(A,20),(D,30)
                                                                             C->(A,10),(D,40)
                                                                             D->(B,30),(C,40) */
            
            string city = i.first; //POINTS TO KEY =A
            list<pair<string, int>> l = i.second; //Points to (B,20),(C,10),(D,50)
            cout << city << " : ";
            for (auto j : l)
            {
                cout << j.first << "," << j.second;
            }
            cout << endl;
        }
    }
};
int main()
{
    graph g;

    g.add_edge("A", "B", true, 20);
    g.add_edge("A", "D", false, 30);
    g.add_edge("A", "C", true, 10);
    g.add_edge("B", "D", true, 30);
    g.add_edge("C", "D", true, 40);
    g.print(); /*the nodes will not be printed in lexographical order since we are using an unordered map
                TO PRINT IN LEXOGRAPHICAL ORDER USE MAP
                */
}
