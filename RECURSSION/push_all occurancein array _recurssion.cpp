#include<bits/stdc++.h>
using namespace std;
int all_occurance(int *a, int n, int i, int key, int *out, int j) {
	if (n == 0)
	{	return j;
	}

	if (a[0] == key)
	{	out[j] = i;
		return all_occurance(a + 1, n - 1, i + 1, key, out, j + 1);
	}

	return all_occurance(a + 1, n - 1, i + 1, key, out, j );
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {2, 3, 7, 3, 7, 9, 7, 5, 3} ;
	int n = sizeof(a) / sizeof(a[0]);
	int out[n];
	int key = 7, count = 0;
	int frq = all_occurance(a, n, 0, key, out, 0);
	cout << "index positision of " << key << " is :" << endl;
	for (int i = 0; i < frq; i++)
		cout << out[i] << " ";
	cout << endl << "no of times  " << key << " appears is " << frq << endl;
}
