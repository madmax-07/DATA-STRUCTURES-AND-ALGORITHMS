#include<bits/stdc++.h>
typedef long long ll;
typedef double  dl;
using namespace std;



//string number to intgers
void string_to_int(string s) {
    vector<int>v;
    //rember in this loop we have got the individual digits only

    for (int i = 0; i < s.length(); i++)
    {   int t = s[i] - '0';
        v.push_back(t);//we are putting the indivual digits insde a vector
    }

    /*for (auto x : v)
    cout << x << " ";*/

//no wconverting the vector digits into  the actual number
    int num = 0;
    for (int i = 0; i < v.size(); i++) {
        num = num * 10 + v[i];
    }
    cout << "number " << num << endl;
}


//recurssive function for converting string number to int
int rec_st_int(string s, int n) {
    if (n == 0) //if len of string is 0
        return 0 ;
    int d = rec_st_int(s, n - 1);
    d = d * 10 + (s[n - 1] - '0');
    return d;
}








int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    string s = "249";
    int n = s.length();
    string_to_int(s);
    cout << rec_st_int(s, n);
}
