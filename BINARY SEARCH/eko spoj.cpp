#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
bool woodcollect(ll *a, ll rw, ll n, ll m)
{	ll wc = 0;
	for (ll i = 0; i < n; i++)
	{	ll
		s = a[i] - m;
		if (s > 0)
			wc += s;
		if (wc >= rw)
			return true;
	}
	//agar true retrun nahi hota matlap reqwood mele nahi
	return false ;
}


int maxheight(ll *a, ll rw, ll n)
{	ll sum = 0, ans = 0;
	//calculating the maximum height
	for (ll i = 0; i < n; i++)
	{ sum += a[i];}
	ll l = 0, h = sum;
	while (l <= h)
	{	ll m = l + (h - l) / 2;
		bool kyawoodmele = woodcollect(a, rw, n, m);
		if (kyawoodmele)
		{	ans = m;
			l = m + 1;
		}
		else //jab wood nahi mele
			h = m - 1;
	}
	return ans;


}





int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif


	ll n, rw;
	cin >> n >> rw;
	ll a[100009];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	cout << maxheight(a, rw, n);
}