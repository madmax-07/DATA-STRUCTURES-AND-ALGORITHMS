#include <bits/stdc++.h>
using namespace std;
bool compare_numeric(pair<string, string> p1, pair<string, string> p2)
{
    string key1 = p1.second;
    string key2 = p2.second;
    return stoi(key1) > stoi(key2);
}
bool compare_lexographic(pair<string, string> p1, pair<string, string> p2)
{
    string key1 = p1.second;
    string key2 = p2.second;
    return key1 > key2;
}

string get_token(string a, int key)
{
    char *ch = new char[a.length() + 1];
    strcpy(ch, a.c_str());
    char *ptr = strtok(ch, " ");
    key--;
    while (key--)
    {
        ptr = strtok(NULL, " ");
    }
    return (string)ptr;
}
int main()
{
    int n;
    cin >> n;
    cin.get();
    string a[n];
    //input 1
    for (int i = 0; i < n; i++)
        getline(cin, a[i]);
    //input 2
    int key;
    cin >> key;
    string comparision_type;
    cin >> comparision_type;
    bool should_reverse;
    cin >> should_reverse;

    //sort the stirngs taken
    pair<string, string> p[n];
    for (int i = 0; i < n; i++)                //we storee the given strings in a pair with its key token 
    {
        p[i].first = a[i];                    // the first value in the pair is the string 
        p[i].second = get_token(a[i], key);   //second value in the pair is the key token 
    }
    // sort according to compare type 
    if (comparision_type == "numeric")
        sort(p, p + n, compare_numeric);
    else 
        sort(p, p + n, compare_lexographic);
    // reverse if required
   if (should_reverse==1)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(p[i], p[n - i - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i].first << endl;
    }
}
