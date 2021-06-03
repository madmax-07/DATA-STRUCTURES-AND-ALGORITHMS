#include <bits/stdc++.h>
using namespace std;
void remove_duplicates(int *a, int n)
{

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int e = a[i];
        while (j >= 0 and a[j] > e)
        {
            int c = j;
            a[c++] = a[j--];
        }
        a[j + 1] = e;
    }
}
int main()
{
    int a[] = {5, 4, 3, 2, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    // s= cooding
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}