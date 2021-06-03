#include <bits/stdc++.h>
using namespace std;
int partition(int *a, int l, int h)
{
    int pivot = a[h];
    int pi = 0;
    for (int i = 0; i < h; i++)
    {
        if (a[i] <= pivot)
            swap(a[i], a[pi++]);
    }
    swap(a[h], a[pi]);
    return pi;
}
void quick_sort(int *a, int l, int h)
{
    if (l < h)
    {
        int pi = partition(a, l, h);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, h);
    }
}

int main()
{
    int a[] = {5, 5, 5, 6, 1, 1, 3, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    // s= cooding
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    return 0;
}