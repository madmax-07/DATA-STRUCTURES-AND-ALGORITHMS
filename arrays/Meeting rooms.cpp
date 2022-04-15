class Solution {
public:
    static bool comp(vector<int>&v1 ,vector<int>&v2){
        return v1[0]<v2[0];
    }
    bool canAttendMeetings(vector<vector<int>>& arr) {
        // the problem sums down to finding if an intervals overlap
        if(arr.size()==0)
            return true;
        sort(arr.begin(),arr.end(),comp);
        int s=arr[0][0];
        int e=arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<e)
                return false;
            s=arr[i][0];
            e=arr[i][1];
        }
        return true;
    }
};
