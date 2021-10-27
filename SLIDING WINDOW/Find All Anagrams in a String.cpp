/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
       if(s.length()<p.length())
           return ans;
        vector<int>word_mp(26,0);
        vector<int>mp(26,0);
        
        //CALCULATE THE VECTOR-map For string P  
        int i;
        int k=p.length();
        for(i=0;i<k;i++){
            word_mp[p[i]-'a']++;
        }
        //for string s in window k
        for(int i=0;i<k;i++){
            mp[s[i]-'a']++;
        }
        if(mp==word_mp)
        ans.push_back(i-k);
        

       
        for(;i<s.length();i++){
        mp[s[i-k]-'a']--;
        mp[s[i]-'a']++;
        if(mp==word_mp)
        ans.push_back(i-k+1);
        
        }
    
        return ans;
    }
        
        
    
};
    
