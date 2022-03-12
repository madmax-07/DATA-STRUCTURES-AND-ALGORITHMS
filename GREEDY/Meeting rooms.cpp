int Solution::solve(vector<vector<int> > &a) {
    vector<int>start(a.size());
    vector<int>End(a.size());
    for(int i=0;i<a.size();i++){
        start[i]=a[i][0];
        End[i]=a[i][1];
    }
    sort(start.begin(),start.end());
    sort(End.begin(),End.end());
    int i=0,j=0,n=a.size(),room_req=0,maxroom=0;
    while(i<n and j<n){
        if(start[i]<End[j])
           {i++;
            room_req++;
            }
          else {
              j++;
              room_req--;
          }
          maxroom=max(maxroom,room_req);
    }
    return maxroom;
}
