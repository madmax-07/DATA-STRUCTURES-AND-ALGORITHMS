/*Given a number ,TASK IS TO FIND THE DIGIT ROOT OF THAT NUMBER .Digital root of a number is found by SUMMING THE DIGITS OF A NUMBER .
IF ITS A SINGLE DIGIT THEN THAT DIGIT IS DIGITAL ROOT OTHER WISE WE REPEAT THE PROCESS*/

/*CONCEPT
If the given number is divisible by 9 then digital root is 9 ,Otherwise digital root is num%9
*/
#include <iostream>
using namespace std;
int main()
{
	string s = "67894534568"; //WE WILL USE STRING TO STORE NUMBER SINCE THE SIZE OF THE NUMBER IS GREATER THAN 10^9.
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum += s[i] - '0';
	}
	if (sum % 9 == 0)
		cout << 9 << endl;
	else
		cout << sum % 9 << endl;
}
