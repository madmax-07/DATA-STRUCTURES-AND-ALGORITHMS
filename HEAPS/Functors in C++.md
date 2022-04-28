## Functional objects/ Functors : 
 * C++ allows function call operator() to be overloaded,such that an object intitated from a class can be called like a function

``` C++
class Fun
{
public:
    void operator()()
    {
        cout << "Having fun inside operator() Fun !";
    }
};
int main()
{
    Fun f;
    f();
}
```
## Priority Queue For Custom Class - Setting our own priority criteria in the Priority Queue 
 N people are standing in a queue find the name of the 3  oldest people.
``` C++
#include <bits/stdc++.h>
using namespace std;
class person
{
public:
    string name;
    int age;
    person(string n, int a)
    {
        name = n;
        age = a;
    }
};
class compare
{
public:
    bool operator()(person a, person b)
    {
        return a.age < b.age;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<person, vector<person>, compare> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        person p(name, age);
        pq.push(p);
    }

    vector<string> ans;
    while (k--)
    {
        ans.push_back(pq.top().name);
        pq.pop();
    }
    for (auto x : ans)
        cout << x << endl;
}
```
#### You would say that in priority_queue compare function why a.age <b.age ?
Compare - A Compare type providing a strict weak ordering.
Note that the Compare parameter is defined such that it returns true if its first argument comes before its second argument in a weak ordering. But because the priority queue outputs largest elements first, the elements that "come before" are actually output last. That is, the front of the queue contains the "last" element according to the weak ordering imposed by Compare.
