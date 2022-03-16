class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        int i=0,j=0,n=s.size();
        map<char,int>mp;
        int len;
        int maxlen=1;
        while(j<n){
           
            mp[s[j]]++;
            // cout<<j<<"#"<<"c"<<s[j]<<"%"<<mp[s[j]]<<endl;
            if(mp[s[j]]>1){
                len=j-i;
                maxlen=max(len,maxlen);
                while(i<j and s[i]!=s[j]){
                    // cout<<i<<"@";
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
        len=j-i;
        maxlen=max(maxlen,len);
        return maxlen;
    }
};
