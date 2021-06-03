#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int *a, int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
int main()
{
    int a[] = {5, 4, 3, 2, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    // s= cooding
    bubble_sort(a, n);
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << endl;
    }
}