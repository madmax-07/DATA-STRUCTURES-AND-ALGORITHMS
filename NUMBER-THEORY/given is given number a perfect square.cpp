/* AIM IS TO check whether a given number is a perfect saqquare or not ?
 WHAT IS A PERFECT SQUARE ?
 A PERFECT SQUARE IS A NUMBER WHO'S SQUARE ROOT IS AN INTEGER.
 Ex: 9 [sqrt(9)=3] or 4,16 etc are perfect squares .WHEREAS NUMBERS SUCH AS 8,6 etc. are not perfect numbers.
 */
#include <bits/stdc++.h>
using namespace std;
bool is_perfect_square(int n)
{
    int y = sqrt(n);
    return y * y == n;
}

int main()
{
    int n;
    cin >> n;
    if (is_perfect_square(n))
        cout << n << " is a perfect square" << endl;
    else
        cout << n << " is not a perfect square"<<endl;
    return 0;
}
