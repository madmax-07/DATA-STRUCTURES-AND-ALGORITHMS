#include <bits/stdc++.h>
using namespace std;
bool compare1(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}
bool compare2(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
bool compare3(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int main()
{
    vector<pair<int, int>> v3;
    int a[] = {11, 9, 3, 8, 5};
    int b[] = {7, 6, 5, 4, 3};

    for (int i = 0; i < 5; i++)
    {
        v3.push_back(make_pair(a[i], b[i]));
    }
    //CASE 1: SORT THE VECTOR ACCORDING TO THE FIRST VALUE in acending order
    sort(v3.begin(), v3.end());
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i].first << ":" << v3[i].second << endl;
    }
    cout << "after sorting" << endl;
    /* O/P- 3:5, 5:3,8:4,9:6,11:7*/

    //CASE 2: SORT THE VECTOR ACCORDING THE FIRST VALUE IN DECENDING ORDER
    sort(v3.begin(), v3.end(), compare1);
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i].first << ":" << v3[i].second << endl;
    }
    cout << endl;
    //CASE 3: SORT ACCORDING TO SECOND VALUE IN acending ORDER
    sort(v3.begin(), v3.end(), compare2);
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i].first << ":" << v3[i].second << endl;
    }
    //CASE 4: SORT ACCORDING TO SECOND VALUE IN descending ORDER
    cout<<endl;
    sort(v3.begin(), v3.end(), compare3);
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i].first << ":" << v3[i].second << endl;
    }
}
