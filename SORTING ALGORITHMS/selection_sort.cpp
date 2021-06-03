#include <bits/stdc++.h>
using namespace std;
void selection_sort(int *a, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_id = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_id])
                min_id = j;
        }
        swap(a[min_id], a[i]); //note humesha what i do is take min=a[i] and try to swap(min,a[i]),what this does is min=0 and a[i]=5 
                            // it will just replace 5 with 0 but not 0 by 5 i.e a[i] will be replaced by min but not a[min_id] and a[i];
    }
}
int main()
{
    int a[] = {5, 4, 3, 2, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    // s= cooding
    selection_sort(a, n);
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << endl;
    }
}