#include<bits/stdc++.h>
typedef long long ll;
typedef double  dl;
using namespace std;


string words(int d)
{   string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
                    "nine"
                   };

    return a[d];
}

void print_words(int n)
{   //n=249;
    if (n == 0)
        return ;
    print_words(n / 10);
    int d = n % 10;
    cout << words(d) << " ";
}






int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    print_words(n);
}

