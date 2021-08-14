  ## VECTORS
  
  ### Important concepts of vectors
- Vectors are **sequential containers** which behave like dynamic arrays,i.e, they store elements in contigous memory locations and can modify their size according to need.
- Supports **random access**. Operation on last element takes O(1) time whereas on other positions it takes O(N) time because insertion is done from end in vectors.
- Traversal is done using iterators. Iterators are objects that point to elements present inside containers.

### Disadvantages of Arrays:
  1. Cannot modify the size of the array once initialized.
  2. Cannot delete elements from array.
  3. Array cannot store elements of different data types.
 
### What does it mean for a vector to be synchronized?
It means that multiple threads can modify the Vector in parallel without risk of data corruption.

### Why Vector are synchronized?
Vector is considered 'thread-safe' because access the the internals of the Vector is synchronized. When one thread is executing a synchronized method for an object, all other threads that invoke synchronized methods for the same object block (suspend execution) until the first thread is done with the object.

  
1. INITIALISATION
  - **Declaring an empty vector and then pushing values**
```cpp
// creates an empty vector 
vector<int> vec;
// WAY 1: push values into vector                                                              push_back adds an element to the end of the array/vector
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);
//WAY :2
vector<int>v;
for(int i = 0; i < 5; i++)
 v.push_back(i); 
//or v[i]=i;
```
- **Specifying size and initializing all values**
```cpp
//creates a vcetor of size 10 with all elemnts as 0
vector<int>vec(10);
// creates a vector of size n with all elements as m
int n = 3;
int m = 10;
vector<int> vec(n, m);
 
```

- **Initializing like arrays**
```cpp
std::vector<int> vec {10, 20, 30, 40, 50};
```

- **Initializing from arrays**
```cpp
int arr[] = {10, 20, 30};
int n = sizeof(arr) / sizeof(arr[0]);
std::vector<int> vec(arr, arr + n); // arr decays to a pointer
```

- **Initializing from another vector**
```cpp
std::vector<int> vec1 {10, 20, 30};
// syntax 1:
std::vector<int> vec2(vec1.begin(), vec.end());
// syntax 2:
std::vector<int> vec2(vec1);
```

### 2. Common Used Methods

#### 2.1 Iterators
- **begin()**: Returns an iterator pointing to the first element in the vector.
- **end()**: Returns an iterator pointing to the theoretical element that follows last element in the vector.
- **rbegin()**: Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
- **rend()**: Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
```cpp
std::vector<int> vec {10, 20, 30};
// forward iteration using iterator
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(), ++it)
	std::cout << *it << std::endl;  // 10 20 30
// backward iteration using reverse iterator
for (std::vector<int>::reverse_iterator itr = vec.rbegin(); itr != vec.rend(); ++itr)
	std::cout << *itr << std::endl; // 30 20 10
```

#### 2.2 Capacity
- **size()**: Returns the number of elements in the vector
- **max_size()**: Returns the maximum number of elements that the vector can hold
- **capacity()**: Returns the size of the storage space currently allocated to the vector expressed as number of elements
- **empty()**: Returns whether the container is empty
```cpp
std::vector <int> vec {10, 20, 30, 40, 50};
std::cout << "Size : " << vec.size() << std::endl;
std::cout << "Capacity : " << vec.capacity() << std::endl;
std::cout << "Max_Size : " << vec.max_size() << std::endl;
/* Output:
Size : 5
Capacity : 8
Max_Size : 4611686018427387903 */
bool is_nonempty_notgood = (vec.size() >= 0); // Try to avoid this
bool is_nonempty_ok = !vec.empty();
//it’s not a good practice to compare v.size() to zero if you want to know whether the container is empty. You’re better off using empty() function:
```

#### 2.3 Accessing vector elements
- **operator [pos]**: Returns a reference to the element at position `pos` in the vector
- **at(pos)**: Returns a reference to the element at position `pos` in the vector
- **front()**: Returns a reference to the first element in the vector
- **back()**: Returns a reference to the last element in the vector

#### 2.4 Modifiers
- **clear()**: Clears the content
- **push_back(const value_type)**: Adds a new element at the end of the vector and increases the vector container size by 1
- **pop_back()**: Removes the element at the end of the vector, i.e., the last element and decreases the vector container size by 1
- **emplace_back(const value_type)**: Appends a new element to the end of the container without extra copy and movement (:warning: `std::vector<bool>` does not support until C++14)
- **emplace(const iterator pos, value_type)**: Inserts a new element into the container directly before `pos` in-place (:warning: `std::vector<bool>` does not support until C++14)
- **erase()**: Removes the element at `pos` or Removes the elements in the range [first, last). Refer to [cppreference](http://en.cppreference.com/w/cpp/container/vector/erase) for syntax details
- **insert()**: Insert elements to the vector
```cpp
// Please be aware that insert() returns the iterator pointing to the newly added elements except syntax 4
std::vector <int> vec(3, 10);    // vec = {10, 10, 10}
// syntax 1: insert a single element
std::vector <int>::iterator it = vec.begin();
it = vec.insert(it, 20);         // vec = {20, 10, 10, 10}
                                           ^
// syntax 2: insert multiple elements of the same value
vec.insert(it, 2, 30);           // vec = {30, 30, 20, 10, 10, 10}
                                                   ^
it = vec.begin();                // vec = {30, 30, 20, 10, 10, 10}
                                           ^
// syntax 3: insert a range of elements from another vector or array
vector <int> vec2(2, 40);        // vec2 = {40, 40}
vec.insert(it + 2, vec2.begin(), vec2.end());
                                 // vec = {30, 30, 40, 40, 20, 10, 10, 10}
int arr[] = {50, 60, 70};
vec.insert(vec.begin(), arr, arr + 3);
                                 // vec = {50, 60, 70, 30, 30, 40, 40, 20, 10, 10, 10}

std::cout << "The elements of the vector are now: ";
for (it = vec.begin(); it < vec.end(); ++it)
	std::cout << *it << (it == vec.end() - 1) ? "\n" : " ";
```
- **resize(size_type)**: Changes the number of elements stored
```cpp
//The resize() function makes vector contain the required number of elements.                 If you require less elements than vector already contain, the last ones will be deleted. If you ask vector to grow, it will enlarge its size and fill the newly created elements with zeroes.                                                                                      Note that if you use push_back() after resize(), it will add elements AFTER the newly allocated size, but not INTO it.
std::vector<int> c = {1, 2, 3};
std::cout << "The vector holds: ";
for(auto& el: c) std::cout << el << ' ';
std::cout << '\n';
c.resize(5);
std::cout << "After resize up 5: ";
for(auto& el: c) std::cout << el << ' ';
std::cout << '\n';
c.resize(2);
std::cout << "After resize down to 2: ";
for(auto& el: c) std::cout << el << ' ';
std::cout << '\n';
c.resize(5);
for (int i = 2; i < 5; i++) {
  c[i] = i * 2;
}
std::cout << "After resize down to 5: ";
for(auto& el: c) std::cout << el << ' ';
//vector<int>c(5);
c.resize(10);
for(int i=5;i<10;i++)
c.push_back(i+1);// Writes to elements with indices [10…15), not [5…10) ! 
 for(auto el:c)
 cout<<el<<' ';
/* Output:
The vector holds: 1 2 3
After resize up 5: 1 2 3 0 0
After resize down to 2: 1 2  
After resize dowm to 5:1,2 4 6 8
After resize down to 10:1,2,4,6,8,0,0,0,0,0,6,7,8,9,10
```
- **swap(vector a, vector b)**: Swaps contents of two vectors
```cpp
std::vector<int> a {10, 20};
std::vector<int> b {30, 40};
a.swap(b);
// a is now {30, 40} while b is {10, 20}
```

#### 2.5 Lower and Upper Bounds for Vectors
```cpp
Iterator lower_bound (Iterator first, Iterator last, const val);
Iterator upper_bound (Iterator first, Iterator last, const val);
```
 
- **lower_bound** returns an iterator pointing to the first element in the range [first, last) which has a value not less than `val`. i.e an iterator pointing to the value itself(if present) else to the value just greater than it(if elemnt not present).
- **upper_bound** returns an iterator pointing to the first element in the range [first, last) which has a value greater than `val`.
- Time complexity of both these function when array/vector <mark>is sorted</mark> is `O(logn)` else when <mark>not sorted</mark> is O(n).So make sure before using these fuction the vector is sorted.
```cpp
std::vector<int> vec {5,6,7,7,6,5,5,6};
std::sort(vec.begin(), vec.end());          // vec = {5 5 5 6 6 6 7 7}

std::vector<int>::iterator lower, upper;
lower = std::lower_bound(v.begin(), v.end(), 6); 
upper = std::upper_bound(v.begin(), v.end(), 6); 
std::cout << "lower_bound for 6 at position " << (lower- v.begin()) << std::endl;
std::cout << "upper_bound for 6 at position " << (upper - v.begin()) << std::endl;
/* Output:
lower_std::cout << "After resize down to 2: ";
for(auto& el: c) std::cout << el << ' ';bound for 6 at position 3
upper_bound for 6 at position 6 */
```

### 3. Supercharge Vector Performance
> By default, use Vector when you need a container.     -----Bjarne Stroutsoup

#### 3.1 Avoid unnecessary reallocate and copy cycles by reserving the size of vector ahead of time
Programmers like vectors because they can just add items to the container without having to worry about the size of the container ahead of time. However, just starting with a vector of capacity 0 and adding to it as elements come in can cost you quite a lot of runtime performance. If you know ahead of time, how big your vector can get, it is worth reserving the size ahead of time.
```cpp
std::vector<int> vec1;
for (int i = 0; i < 10000; ++i)
	vec1.push_back(i);
    
// better version
std::vector<int> vec2;
vec2.reserve(10000);
for (int i = 0; i < 10000; ++i)
	vec2.push_back(i);
```

#### 3.2 While iterating through elements in a std::vector, avoid the `std::vector::at()` function

#### 3.3 Try to avoid inserting an element in front of the vector
Any insert at the front of a vector is an O(n) operation. Inserting at the front is inefficient because every item in the vector must be copied to make room for the new entry. If you need to continually insert at the beginning of the vector, you should probably re-evaluate your overall design (maybe use `std::list` instead).

#### 3.4 Use `shrink_to_fit()` to release memory consumed by the vector, `clear()` or `erase()` does not release memory
Contrary to popular belief, removing the elements from a vector via the erase() or clear() methods does not release the memory allocated by the vector.
```cpp
std::vector<int> v;
std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
v.resize(100);
std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
v.clear();
std::cout << "Capacity after clear() is " << v.capacity() << '\n';
v.shrink_to_fit();
std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
/* Output:
Default-constructed capacity is 0
Capacity of a 100-element vector is 100
Capacity after clear() is 100
Capacity after shrink_to_fit() is 0 */


```

#### 3.5 When filling up or copying into a vector, prefer assignment over `insert()` or `push_back()`
There are three popular ways of filling up a vector from another vector: assigning the old vector to the new one, using the iterator-based `std::vector::insert()` or using a loop-based `std::vector::push_back()`.
```cpp
std::vector<int> vec1 {10, 20, 30};
std::vector<int> vec2;
// simple and efficient way of copying vector
vec2 = vec1;
```

#### 3.6 Prefer `emplace_back()` instead of `push_back()` while inserting into a vector
Almost everyone who jumped onto the C++11 bandwagon unequivocally agrees that emplacement is favorable to insertion for STL containers. Theoretically, emplacement is supposed to be at least as efficient as insertion. However, for all practical purposes , sometimes the difference in performance is negligible.

Emplacement functions are likely to be significantly faster only in the following cases:
- The value being added is constructed into the vector, not assigned.
- The argument type(s) passed differ from the type held by the vector. For example, if a vector contains std::string but we pass a string literal to the vector.

Even if the above two conditions don’t hold true, you’ll not lose much by using emplacement over insertion.
