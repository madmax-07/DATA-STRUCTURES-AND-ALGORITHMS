/*Method 1: In the first iteration count the number of 0's,1's and 2's and then in the socind iteration first insert the counted zero's and then 1's and then 2's.
t(n)=O(n) but it takes two iteration

Method 2: In this optimised approach we only need to iterate the array once .The concept is based on using three pointers : Low,Mid,high
0 -> low-1 : 0's
low -> high  : 1's
high+1 -> n :2's

**The mid is used to traverse 

Algorithm :
if a[mid]==0
swap(a[mid],a[low]
low++,mid++;

else if a[mid]==1
mid++;

else if a[mid]==high
swap(a[mid],a[high])
high--;

*/

void sortColors(vector<int> &a)
{
    int n = a.size(), low = 0, mid=0, high = n - 1;
    

    while (mid <=high)
    {
        if (a[mid] == 0)
        {
            swap(a[low++], a[mid++]);
            
        }
        else if (a[mid] == 1)
        mid++;
        else if (a[mid] == 2)
        {
            swap(a[high--], a[mid]);
            
        }
    }
}
