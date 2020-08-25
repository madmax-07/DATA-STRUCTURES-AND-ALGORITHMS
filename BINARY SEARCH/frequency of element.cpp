#include <bits/stdc++.h>
using namespace std;
int firstoccurance(int *a, int n, int key)
{	int l, h, ans;
	l = 0;
	h = n - 1;
	while (l <= h)
	{	int m = l + (h - l) / 2;
		if (a[m] == key)
		{	ans = m;
			h = m - 1;
		}
		else if (a[m] < key)
		{	l = m + 1;
		}
		else
		{h = m - 1;}
	}
	return ans;
}
int lastoccurance(int *a, int n, int key)
{	int l = 0, h = n - 1, ans;
	while (l <= h)
	{	int m = l + (h - l) / 2;
		if (a[m] == key)
		{	ans = m;
			l = m + 1;
		}
		else if (a[m] > key)
		{	h = m - 1;
		}
		else
		{l = m + 1;}
	}
	cout << ans << endl;
	return ans;
}
int  main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//method 1: traverse the array and count the no of occurances through it





	int a[] = {1, 1, 2, 2, 2, 2, 3,},   key = 2;
	int n = sizeof(a) / sizeof(a[0]);

	int fo = firstoccurance(a, n, key);
	int lo = lastoccurance(a, n, key);
	cout << lo << endl << fo << endl;
	int freq = lo - fo + 1;
	cout << freq;
}


