/*aproach that we folow inhere is :
Step 1: Sort the aray according to the staring time of the intervals
Step 2: Store the staring and ending point of the first intervals in some variable 
Step 3: after that for the further intervals if :
        (a) v[i][0]<e then merge the intervals and decid the ending point {(1,4),(2,3)==(1,4)}
        (b) v[i][0]>e then the intervals wont be merged rather this becomes the new comparing point
*/

class Solution {
public:
    static bool comp( vector<int> &v1,  vector<int> &v2)
{
    return v1[0] < v2[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort the vector accorinding tothe first elemnt 
        vector<vector<int>>ans;
        //step 1 :sort  the stack according to the starting time of the interval 
        sort(intervals.begin(), intervals.end(), comp);
        int s=intervals[0][0];
        int e=intervals[0][1];
        vector<int>v;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=e){
                e=(intervals [i][1]>e)?intervals[i][1]:e;
            }
            else {
                v.push_back(s);
                v.push_back(e);
                ans.push_back(v);
                v.clear();
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
    v.push_back(s);
    v.push_back(e);
    ans.push_back(v);
    v.clear();
        return ans;
    }
};
