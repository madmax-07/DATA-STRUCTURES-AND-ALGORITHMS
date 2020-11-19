#include<bits/stdc++.h>
using namespace std;
int kadane(int start, int end, vector<int>v) {
	int n = v.size();
	int sum = 0, maxsum = 0, s = start, i = s % n;
	while (i != end) {
		sum += v[i];
		if (sum < 0)
			sum = 0;
		maxsum = max(sum, maxsum);
		s++;
		i = s % n;
	}
	return maxsum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;

		vector<int>v(n);
		for ( int i = 0; i < n; i++)
			cin >> v[i];
		//travesring the array
		int maxsum = 0;
		int  start = 0, end = n - 1, end_index = end % n;
		while (start <= n - 1) {
			int sum = kadane(start, end_index, v);
			maxsum = max(sum, maxsum);
			start++;
			end++;
			end_index = end % n;
		}
		cout << maxsum << endl;
	}

	return 0;
}