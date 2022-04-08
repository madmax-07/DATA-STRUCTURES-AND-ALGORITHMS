#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, x);
    s.push(temp);
}
void sort(stack<int> &s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    sort(s);
    insert(s, x);
}
int main()
{
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);
    sort(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
