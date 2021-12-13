/*Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example
Given:
length = 5,
updates = 
[
[1,  3,  2],
[2,  4,  3],
[0,  2, -2]
]
return [-2, 0, 3, 5, 3]

Explanation:
Initial state:
[ 0, 0, 0, 0, 0 ]
After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]
After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]
After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
*/
class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here
        vector<int>ans(length,0);
        vector<int>prefix(length+1,0);
        for(int i=0;i<updates.size();i++){
           int start=updates[i][0];
           int end=updates[i][1];
           int upd=updates[i][2];
           prefix[start]+=upd;
           prefix[end+1]-=upd;
           }
        for(int i=1;i<prefix.size();i++){
            prefix[i]=prefix[i-1]+prefix[i];
        }
    prefix.pop_back();
    return prefix;
    }
};
