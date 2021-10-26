/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
    map<string,vector<string>>mp;
    for(int i=0;i<s.size();i++){
        string str=s[i];
        sort(str.begin(),str.end());
        mp[str].push_back(s[i]);
    }
        vector<vector<string>>ans;
    for(auto i:mp){
        vector<string>v;
    for(auto x:i.second){
        v.push_back(x);
    }
     ans.push_back(v);
     v.clear();    
    }
        return ans;
    }
  /*tc:O(nklogk)*/
  
    
};
