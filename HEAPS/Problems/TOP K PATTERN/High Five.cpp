/*
Description
Each student has two attributes ID and scores. Find the average of the top five scores for each student.

Example
Example 1:

Input: 
[[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]
Output:
1: 72.40
2: 97.40
Example 2:

Input:
[[1,90],[1,90],[1,90],[1,90],[1,90],[1,90]]
Output: 
1: 90.00
*/
/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here
    
        map<int,priority_queue<int,vector<int>,greater<int>>>mp;//a min heap
        for(int i=0;i<results.size();i++){
           
            mp[results[i].id].push(results[i].score);
            if(mp[results[i].id].size()>5)
            mp[results[i].id].pop();
        }
    
        map<int,double>ans;
        for(auto it:mp){
            priority_queue<int,vector<int>,greater<int> >pq=it.second;
            double avg=0;
            while(!pq.empty()){
            avg+=pq.top();
            pq.pop();
            }
            ans[it.first]=avg/5;
        }
        return ans;
    }
};
/*tc: o(Nlogn)
  sc:O(n)
 */
