#include <bits/stdc++.h>
using namespace std;
void count_sort(int *a, int n)
{
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        while (count[i] > 0)
        {
            a[k++] = i;
            count[i]--;
        }
    }
}
int main()
{
    int a[] = {5, 5, 5, 6, 1, 1, 3, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    // s= cooding
    count_sort(a, n);
    for (int i = 0; i < n; i++)
    {

        cout << a[i] <<" ";
    }
    return 0;
}