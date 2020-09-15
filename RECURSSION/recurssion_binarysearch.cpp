#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//template fined

int binary_search(vector<int>&v, int low, int high, int key)
{	if (low <= high) {
		int m = low + (high - low) / 2;
		if (v[m] == key)
			return m;
		else if (v[m] < key)
			return binary_search(v, m + 1, high, key);
		else
			return binary_search(v, low, m - 1, key);
	}
	return -1;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, p;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{	cin >> p;
		v.pb(p);
	}
	int key;
	cin >> key;
	int m = binary_search(v, 0, v.size() - 1, key) ;
	if (m != -1)
		cout << "index fount at " << m + 1 << endl;
	else
		cout << "index not present" << endl;

}




