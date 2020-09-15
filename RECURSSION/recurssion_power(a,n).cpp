#include<bits/stdc++.h>
using namespace std;
int power(int a, int n)
{
	if (n == 1)
		return a;
	else
		return a * power(a, n - 1);


}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int a, n;
		cin >> a >> n;
		cout << power(a, n) << endl;
	}


}