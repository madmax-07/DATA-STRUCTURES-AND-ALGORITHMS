#include<bits/stdc++.h>
typedef long long ll;
typedef double  dl;
using namespace std;


int partition(int *a, int low, int high)
{   int pi = low, pivot = high;
    for (int i = low; i < high; i++)
    {   if (a[i] < a[pivot])
        {   swap(a[i], a[pi]);
            pi++;
        }
    }
    swap(a[pivot], a[pi]);
    return pi;
}
void  quick_sort(int *a,  int low, int high)
{   //base case

    if (low < high)
    {   int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }





}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    int a[] = {2 , 4, 5, 1, 7, 0, 3, 8, 6};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort(a, 0, n - 1) ;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}


