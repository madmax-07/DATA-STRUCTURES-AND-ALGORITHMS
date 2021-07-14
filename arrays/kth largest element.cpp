#include <bits/stdc++.h>
using namespace std;
/*METHOD 1: SORT THE ARRAY AND THEN INDEX THE K-1th ELEMENT T(N)=nlogn and space complexity is o(n)

OPTIMISED APPROACH:
IN THE FOLLOWING METHOD WE SOLVE HAVE USED A TWEAKED VERSION OF QUCIK SORT METHOD WHERE WE STOP WHEN THE PARTITION INDEX IS K-1TH ELEMNT
t(n)<nlogn and Sapce complexity=O(1) 

*/

int partition(vector<int> &v, int low, int high, int k)
{
	int pivot = v[high], pi = low;
	if (low < high)
	{

		for (int i = low; i <= high - 1; i++)
		{
			if (v[i] <= pivot)
			{
				swap(v[i], v[pi]);
				pi++;
			}
		}
		swap(v[pi], v[high]);
		if (pi == k)
		{
			return v[pi];
		}
		else if (pi < k)
			return partition(v, pi + 1, high, k);
		else if (k < pi)
			return partition(v, low, pi - 1, k);
	}
	return v[pi];
}

int findKthLargest(vector<int> &v, int k)
{
	int n = v.size();
	return partition(v, 0, n - 1, n - k); //note if it woulD hav ebeen smallest we would have just passsed k-1 instaed of n-k
}

int main()
{
	vector<int> v{3, 2, 3, 1, 2, 4, 5, 5, 6};
	int k = 4;

	cout << findKthLargest(v, k) << endl;
}
