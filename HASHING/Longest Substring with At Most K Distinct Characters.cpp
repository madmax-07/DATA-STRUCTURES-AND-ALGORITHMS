class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if(s==""||k==0)
        return 0;
       int maxlen=INT_MIN,len;
        map<char,int>mp;
        int i=0,j=0,n=s.length();
        while(j<n and mp.size()<=k){
            mp[s[j]]++;
            if(mp.size()>k){
                len=j-i;
                maxlen=max(len,maxlen);
                while(i<j and mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                     mp.erase(s[i]);
                     i++;
                }
            }
                j++;
            }
            len=j-i;
            maxlen=max(maxlen,len);
        
        return maxlen;
    }
};
