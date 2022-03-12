int Solution::mice(vector<int> &a, vector<int> &b) {
sort(a.begin(),a.end());
sort(b.begin(),b.end());
int dis=0;
int max_time=0;
for(int i=0;i<a.size();i++)
{ dis=abs(a[i]-b[i]);
  max_time=max(max_time,dis);
}
return max_time;
}


