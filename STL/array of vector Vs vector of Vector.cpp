#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v[5];
    /*This is an array of vector.An array of the type vector which means that  v[0]/v[1]/v[2]...v[5]  stores vector but 
    make  a note here that V can't grow. You cannot make V1.push_back(...) as its not a vector object.

    // in the following implementation we store the multiplication table in each array index.AT a[0]->multiplication table of 1 and so on
*/
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= 10; j++)
            v[i].push_back((i + 1) * j);
    }
    for (int i = 0; i < 5; i++)
    {
        for (auto x : v[i])
            cout << x << " ";
        cout << endl;
    }
    /* o/p : 
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20
3 6 9 12 15 18 21 24 27 30
4 8 12 16 20 24 28 32 36 40
5 10 15 20 25 30 35 40 45 50
*/

    //----------END OF EXPLANATION 1 ------------------------------------------------------

    vector<vector<int>> v1;
    /*Vector of Vectors is a two-dimensional vector with a variable number of rows where each row is vector. 
    Each index of vector stores a vector which can be traversed and accessed using iterators.
     It is similar to an Array of Vectors but with dynamic properties.*/

    vector<int> v2;
    for (int i = 0; i < 5; i++)
        v2.push_back(i + 1);
    v1.push_back(v2);
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j];
        }
        cout << endl;
    }

    //----------------------------END OF EXPLANATION 2---------------------------------------------------------------
