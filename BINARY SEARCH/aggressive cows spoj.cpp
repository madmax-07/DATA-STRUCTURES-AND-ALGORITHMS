#include<bits/stdc++.h>
using namespace std;
bool cowsrakpaye(int*a, int c, int n, int m )
{	int cowcount = 1;
	int last_cow = a[0];
	for (int i = 1; i < n; i++)
	{	if (a[i] - last_cow >= m)
		{	last_cow = a[i];
			cowcount++;
			if (cowcount == c)
			{return 1;}
		}
	}
	return 0;
}
int maximum_distance(int *a, int cow , int n)
{	int low, high, ans = 0;
	low = 0, high = a[n - 1] - a[0] ;
	while (low <= high)
	{	int m = low + (high - low) / 2;
		//check if mid distance pai hum given no of cows rakh pa rahe h ya nahi ?
		int rakhpaye = cowsrakpaye(a, cow, n, m);
		if (rakhpaye)
		{	ans = m;
			low = m + 1; //we will serach for the next big no
		}
		else
			high = m - 1;
	}
	return ans;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// maximizing the minimum distance in cows

	int a[] = {1, 2, 4, 8, 9}, c = 4;
	int n = sizeof(a) / sizeof(a[0]);
	int distance = maximum_distance(a, c, n);

	cout << distance << endl ;
	return 0;






}