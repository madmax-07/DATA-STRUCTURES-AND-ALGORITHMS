#include <bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    list<int> *l;

public:
    graph(int v) //constructor
    {
        this->v = v; /*'this' pointer points to/stores the address of the object which evokes the member function
                       in the given senarior it refers to /points to g*/  
        l = new list<int>[v];
    }
    void add_edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printGraph()
    {
        //print the array of list
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (auto x : l[i])
                cout << x<<"->";
            cout << endl;
        }
    }
};
int main()
{
    graph g(4); //calling a constructor to initialise the list
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.printGraph();
    return 0;
}
