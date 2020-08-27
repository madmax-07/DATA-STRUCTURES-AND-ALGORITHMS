#include<bits/stdc++.h>
using namespace std;
int roation_count(int *a, int n)
{	int low, high;
	low = 0, high = n - 1;
	while (low <= high)
	{	int m = low + (high - low) / 2;
		//check if mid itself is the  min
		if (a[m - 1] > a[m] && m > low)
			return m;
		//check if a[M+1] is the mid
		else if (a[m] > a[m + 1] && m < high)
		{	return m + 1;

		}
		//if mid lies in the left half
		else if (a[high] > a[m])
		{
			high = m - 1;
		}
		//if min lies in the right half
		else if (a[m] > a[high])
			low = m + 1;
	}
	return -1;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//how many times a sorted array has been roatated ?

	int a[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(a) / sizeof(a[0]);
	int element = roation_count(a, n);
	if (element != -1)
		cout << "array has been roatated by : " << element ;
	else
		cout << "Array has not been roated ";






}