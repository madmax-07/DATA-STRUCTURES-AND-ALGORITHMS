#include <bits/stdc++.h>
using namespace std;
void merge(int *a, int l, int h, int m)
{
    int k = l;
    int i = l;
    int j = m + 1;
    int temp[100];
    while (i <= m and j <= h)
    {
        if (a[i] > a[j])
            temp[k++] = a[j++];
        else
            temp[k++] = a[i++];
    }
    while (i <= m)
    {
        temp[k++] = a[i++];
    }
    while (j <= h)
    {
        temp[k++] = a[j++];
    }
    for (int i = l; i <= h; i++)
        a[i] = temp[i];
}
void merge_sort(int *a, int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, h);
        merge(a, l, h, m);
    }
}
int main()
{
    int a[] = {5, 5, 5, 6, 1, 1, 3, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    // s= cooding
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    return 0;
}