### what are void pointers ? <br>
A void pointer is a pointer that has no associated data type with it. A void pointer can hold address of any type and can be typcasted to any type.

``` C++
int a = 10;
char b = 'x';

void *p = &a;  // void pointer holds address of int 'a'
p = &b; // void pointer holds address of char 'b'
```


https://www.hackerearth.com/practice/notes/void-pointer-in-c/
