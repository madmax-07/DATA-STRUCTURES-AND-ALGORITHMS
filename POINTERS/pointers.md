## WHAT ARE VOID POINTERS <br>
A void pointer is a pointer that has no associated data type with it. A void pointer can hold address of any type and can be typcasted to any type.

``` C++
int a = 10;
char b = 'x';

void *p = &a;  // void pointer holds address of int 'a'
p = &b; // void pointer holds address of char 'b'
```
NOTE : A void pointer can't be derefrenced.The following functions gives an error

```C++
int main()
{
    int a = 10;
    void *ptr = &a;
    printf("%d", *ptr);
    return 0;
}
```
```
O/P : Compiler Error: 'void*' is not a pointer-to-object type
```
for more refer below:
https://www.hackerearth.com/practice/notes/void-pointer-in-c/

## WHAT IS AN ARRAY OF POINTERS
An array that contains pointers as its elements.Every element of the array is a pointer variable that holds address of any variable of the appropriate type.

```
datatype *arr[size]
```
```C++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 5, b = 6, c = 7;
    int *arr[3];
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}
```
