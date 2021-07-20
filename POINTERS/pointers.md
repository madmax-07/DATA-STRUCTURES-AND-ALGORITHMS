### What are void pointers ? <br>
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
Compiler Error: 'void*' is not a pointer-to-object type
```


https://www.hackerearth.com/practice/notes/void-pointer-in-c/
