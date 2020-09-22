#include<bits/stdc++.h>
typedef long long ll;
typedef double  dl;
using namespace std;


int merge(int *a, int low, int high, int m)
{
    int i = low, j = m + 1, k = low;
    int temp[100], ic = 0;
    while (i <= m && j <= high) {
        if (a[i] < a[j])
        {   temp[k] = a[i];
            k++; i++;
        }
        else {//i.e if a[i]>a[j]
            ic += m - i + 1;
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
    return ic;
}
int  merge_sort(int *a,  int low, int high)
{   //base case
    int ic = 0 ;
    if (low < high)
    {   int m = low + (high - low) / 2;
        ic += merge_sort(a, low, m);//we count the ic from the left arra
        //we countthe ic form the right array
        ic += merge_sort(a, m + 1, high);
        //we conut the both halves
        ic += merge(a, low, high, m);
    }
    return ic;




}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int ic =  merge_sort(a, 0, n - 1) ;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl << "inversion count " << ic << endl;
}



