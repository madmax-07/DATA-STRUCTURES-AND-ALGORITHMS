/*
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
 

Constraints:

1 <= s.length <= 5 * 104
0 <= k <= 50
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        //take two pointers
        //aabcbcdbca
        if(k==0 ||s.length()==0) return 0;
        int maxlen=1;
        int i=0;int j=0;
        int n=s.length();
        map<char,int>mp;
             while(j<n and mp.size()<=k){
                  mp[s[j]]++;
                  if(mp.size()>k){
                  maxlen=max(maxlen,j-i);
                  while(i<j and mp.size()>k)
                  { mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                  }
                }      
               j++;
            }
    
        maxlen=max(maxlen,j-i);
        return maxlen;
    }
        
};
