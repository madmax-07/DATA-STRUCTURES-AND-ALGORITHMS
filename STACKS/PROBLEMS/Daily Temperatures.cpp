class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int,int>>s;
        int n=arr.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and s.top().first<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=0;
            }
            else ans[i]=s.top().second-i;
            s.push({arr[i],i});
        }
        return ans;
    }
};
