#include<bits/stdc++.h>
using namespace std;
int find_element(int *a, int n, int key)
{	int l, h;
	l = 0, h = n - 1;
	while (l <= h)
	{	int m = l + (h - l) / 2;
		if (a[m] == key)
			return m;
		else if (a[l] <= a[m])
		{	if (a[l] <= key && key <= a[m])
				h = m - 1;
			else
				l = m + 1;
		}
		else
		{	if (key >= a[m] && key <= a[h])
				l = m + 1;
			else
				h = m + 1;
		}
	}
	return -1;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {4, 5, 6, 1, 2, 3}, key = 5;
	int n = sizeof(a) / sizeof(a[0]);
	int element = find_element(a, n, key);
	cout << "elemnet present at " << element + 1;






}