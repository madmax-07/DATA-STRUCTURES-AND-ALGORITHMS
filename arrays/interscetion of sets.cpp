#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &a, vector<int> &b)
{
    set<int> s1; //SPACE COMPLEXITY OF SET IS GOING TO BE O(n)
    set<int> s2;
    vector<int> v; 
    for (int i = 0; i < a.size(); i++) //TIME COMPLEXITY IS GOING TO BE O(M) FOR CONVERTING ARRAY A TO SET1
        s1.insert(a[i]);

    for (int i = 0; i < b.size(); i++) //TIME COMPLEXITY IS GOING TO BE O(M) FOR CONVERTING ARRAY B TO SET2
        s2.insert(b[i]);
        
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        if (s2.find(*it) != s2.end())
            v.push_back(*it);
    }
    return v;
}
}
int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{1, 2, 3, 7};
    vector<int>v;

    v=intersection(a,b);
    for(auto x:v){
        cout<<x<<endl;
    }
}
