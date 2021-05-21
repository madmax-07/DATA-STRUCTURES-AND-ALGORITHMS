#include <bits/stdc++.h>
using namespace std;
bool is_perfect_square(int n)
{
    int y = sqrt(n);
    return y * y == n;
}

int main()
{
    int n;
    cin >> n;
    if (is_perfect_square(n))
        cout << n << " is a perfect square" << endl;
    else
        cout << n << " is not a perfect square"<<endl;
    return 0;
}
