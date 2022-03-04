```C++

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
 int ans=0;
 int n=arr.size();
 vector<int>visted(n,0);
 vector<pair<int,int>>v;
 for(int i=0;i<arr.size();i++){
     v.push_back({arr[i],i});
 }
 sort(v.begin(),v.end());
 
 for(int i=0;i<n;i++){
     
     if(visted[i] || v[i].second==i)
      continue;
      int j=i;
      int len=0;
      while(visted[j]==0){
          len++;
          visted[j]=1;
          j=v[j].second;
      }
      ans+=len-1;
     
 }
 return ans;
}
//
```
