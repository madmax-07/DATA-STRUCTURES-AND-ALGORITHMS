          #include <bits/stdc++.h>
using namespace std;
class heap
{
    vector<int> v;
    bool minheap;
    bool compare(int child, int parent)
    {
        if (minheap)
            return child < parent;
        else
            return child > parent;
    }
    /* Max-heapify is a process of arranging the nodes in correct order so that they follow max-heap property.
       Min-heapify is a process of arranging the nodes in correct order so that they follow min-heap property.
    */
    void heapify(int id)
    {
        int left = 2 * id;
        int right = left + 1;
        int min_index = id;
        int last = v.size() - 1;
        if (left <= last and compare(v[left], v[id]))
        {
            min_index = left;
        }
        if (right <= last and compare(v[right], v[min_index]))
        {
            min_index = right;
        }
        if(min_index!=id)
        {
                  swap(v[min_index],v[id]);
                  heapify(min_index);
        }
    }
public:
    heap(int ds = 10, bool type = true)
    {
        v.reserve(ds);
        v.push_back(-1);
        minheap = type;
    }
    void push(int d)
    {
        v.push_back(d);
        //get it to satisy heap order property
        int last = v.size() - 1;
        int parent = last / 2;
        while (last > 1 and compare(v[last], v[parent]))
        {
            swap(v[last], v[parent]);
            last = parent;
            parent = parent / 2;
        }
    }
    void pop()
    {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1;
    }
    int top()
    {
        return v[1];
    }
};
int main()
{
    heap h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
}
