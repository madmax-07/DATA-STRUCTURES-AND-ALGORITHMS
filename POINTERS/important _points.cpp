#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x = 52;
	cout << &x << endl;
	char c = 'A';
	/*this does not prints the address of the charachter array 
	WHY??
	when we do cout<<&c .Its interpretted as char*.operator<< i.e as a  C-string (A concept of operator overloading)
	*/
	//cout << &c << endl;

	cout << (void *)&c << endl;
	/*in the above code we get the address of the char c as (&c)-> this represeants the address of charchter c
	and then we are typecasting it to the (void*) data type.basically we are telling the complier
	that the adress we are suppliying is of the type void* not of char*  and hence we get the printed value
	same result : (int*)&c */
}
