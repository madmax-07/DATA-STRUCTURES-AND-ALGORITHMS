#include<bits/stdc++.h>
typedef long long ll;
typedef double  dl;
using namespace std;



int no_of_ways(int n) {
//f(n)=1*f(n-1)+(n-1)f(n-2)
    if (n <= 1) //f(1)=1 &&f(0)=1 if no one goes then ek he way hai koi bhi nahi jayega
        return 1; //f(1) =1 since he has only one way to go ,ie is alone
    else
        return 1 * no_of_ways(n - 1) + (n - 1) * no_of_ways(n - 2);

}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    //friends pairing problem
    int n;
    cin >> n;
    cout << no_of_ways(n) << endl;
}
