#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(int a[], int start , int end) {
	int size = (end - start) + 1;
	//base case
	if (size <= 1)
		return 1;
	if (a[start] != a[end])
		return 0 ;
	else
	{
		start++; end--;
		return is_palindrome(a, start, end);
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int start = 0, end = n - 1;

	if (is_palindrome(a, start, end))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}




