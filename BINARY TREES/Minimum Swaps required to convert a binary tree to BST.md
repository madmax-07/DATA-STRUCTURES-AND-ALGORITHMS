
```C++
void inorder(vector<int>&arr,vector<int>&v,int n,int i){
    if(i>=n)
        return;
    inorder(arr,v,n,2*i+1);
    v.push_back(arr[i]);
    inorder(arr,v,n,2*i+2);
    
}
int min_swaps(vector<int>&va,int n){
    vector<pair<int,int>>a;
    int ans=0;
    for(int i=0;i<n;i++){
        a.push_back({va[i],i});
    }
    sort(a.begin(),a.end());
    vector<int>visted(n,0);
    for(int i=0;i<n;i++){
        if(visted[i]||a[i].second==i)
            continue;
        int j=i;
        int len=0;
        while(visted[j]==0){
            len++;
            visted[j]=1;
            j=a[j].second;
        }
        ans+=len-1;
    }
    return ans;
}
int minimumSwaps(vector<int>&arr, int n) {
	// Write your code here
    vector<int>v;
    inorder(arr,v,n,0);
    return min_swaps(v,n);
}
```
