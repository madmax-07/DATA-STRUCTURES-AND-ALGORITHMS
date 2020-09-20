#include<bits/stdc++.h>
using namespace std;
int all_occurance(int *a, int n, int i, int key, int count) {
	if (n == 0)
	{	cout << endl;
		return count;
	}

	if (a[0] == key)
	{	cout << i << " ";
		count++;
	}

	return all_occurance(a + 1, n - 1, i + 1, key, count);
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {2, 3, 7, 3, 7, 9, 7, 5, 3}, n, i;
	n = sizeof(a) / sizeof(a[0]);
	int key = 3, count = 0;
	cout  << all_occurance(a, n, 0, key, count);
}