#include<bits/stdc++.h>
using namespace std;
int kadane(int start, int end, vector<int>v) {

	int sum = 0, maxsum = 0;
	for (int i = start; i < end; i++) {
		sum += v[i];
		if (sum < 0)
			sum = 0;
		maxsum = max(sum, maxsum);

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

	int t, n, i;
	cin >> t;

	while (t--) {
		cin >> n;
		vector<int>v(n);
		for (i = 0; i < n; i++)
			cin >> v[i];
		int umwrap_sum = kadane(0, n, v);
		//this considers the edge case if alll the given elemnts in array are -ve
		//i.e a[]={-3,-9,-2,-1}-> max sum =-1;
		if (umwrap_sum == 0) {
			sort(v.begin(), v.end(), greater<int>());

			return v[0];
		}
		else {
			int total_sum = 0;
			for (i = 0; i < n; i++)

			{	total_sum += v[i];
				v[i] = -1 * v[i];
			}
			int non_contributingsum = kadane(0, n, v);
			total_sum = total_sum + non_contributingsum;
			int max_circularsum = max(total_sum, umwrap_sum);
			cout << max_circularsum << endl;
		}
	}

	return 0;
}