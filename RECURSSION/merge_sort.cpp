#include<bits/stdc++.h>
typedef long long ll;
typedef double  dl;
using namespace std;


void merge(int *a, int low, int high, int m)
{
    int i = low, j = m + 1, k = low;
    int temp[100];
    while (i <= m && j <= high) {
        if (a[i] < a[j])
        {   temp[k] = a[i];
            k++; i++;
        }
        else {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= m)
    {   temp[k] = a[i];
        i++; k++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        k++; j++;
    }
    for (int i = 0; i <= high; i++)
        a[i] = temp[i];
}
void merge_sort(int *a,  int low, int high)
{   //base case

    if (low < high)
    {   int m = low + (high - low) / 2;
        merge_sort(a, low, m);
        merge_sort(a, m + 1, high);
        merge(a, low, high, m);
    }




}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}



