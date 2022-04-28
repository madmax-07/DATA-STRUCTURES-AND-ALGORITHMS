## Functional objects/ Functors : 
 * C++ allows function call operator() to be overloaded,such that an object intitated from a class can be called like a function

``` C++
class Fun
{
public:
    void operator()()
    {
        cout << "Having fun inside operator() Fun !";
    }
};
int main()
{
    Fun f;
    f();
}
```
## Priority Queue For Custom Class
 N people are standing in a queue find the name of the 3 tallest people.
```
