int Solution::maxp3(vector<int> &a) {
sort(a.begin(),a.end(),greater<int>());
int j=0,i=0,n=a.size();
while(j<n and a[j]>0)
  j++;
  if(j>=n-1||j==0)//all positive
  { int ans=a[i]*a[i+1]*a[i+2];
    return ans;
  }
//   if(j==0)//all negative
//    {int ans=a[0]*a[1]*a[n-1];
//      return ans;
//    }
  
  int ans1=a[0]*a[1]*a[2];
   int ans2=a[n-1]*a[n-2]*a[0];
    return max(ans1,ans2);
}
