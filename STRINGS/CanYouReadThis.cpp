/*One of the important aspect of object oriented programming is readability of the code. To enhance the readability of code, developers write function and variable names in <a href="https://en.wikipedia.org/wiki/Camel_case">Camel Case</a>. You are given a string, S, written in Camel Case. FindAllTheWordsContainedInIt.
Input Format: A single line contains the string.
Sample Input: IAmACompetitiveProgrammer
Output Format: Print words present in the string, in the order in which it appears in the string.
Sample Output: I
Am
A
Competitive
Programmer*/

#include <bits/stdc++.h>
using namespace std;
bool isupper(char c){
    if((int)c>=(int)'A' && (int)c<=(int)'Z')
    return true;
    else return false;

}
int main()
{
    string s;
    string str="";
    getline(cin, s);
    int i = 0;
    while (i < s.length())
    { str += s[i];
     i++;
    while(i<s.length() && !isupper(s[i]))
        {str += s[i++];
        }
    cout<<str<<endl;
    str="";
    }
}
