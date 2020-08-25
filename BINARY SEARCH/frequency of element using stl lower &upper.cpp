#include <bits/stdc++.h>
using namespace std;

int  main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//method 1: traverse the array and count the no of occurances through it





	int a[] = {1, 1, 2, 2, 2, 2, 3,},   key = 2;
	int n = sizeof(a) / sizeof(a[0]);
	auto it = lower_bound(a, a + n, key);//lower_bpund retruns the add of first elemnt>=key
	int fo = it - a;

	auto it1 = upper_bound(a, a + n, key);//upper_bound returns the address of element >key
	int lo = it1 - a;

	int freq = lo - fo ;
	cout << freq << endl;
}


