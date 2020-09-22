#include<bits/stdc++.h>
typedef long long ll;
typedef double  dl;
using namespace std;
//fast power recurssion is fast as there are only n/2^k calls to the stack.
//the complexity reduces to O(log(n)) instead of O(n) in the normal method
int  fast_power(int a, int n)
{
    if (n == 1)
        return a;
    int ans = fast_power(a, n / 2);
    ans *= ans;
    if (n & 1)
        return ans * a;
    else
        return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a , n;
    cin >> a >> n;
    cout << fast_power(a, n) << endl;
}



