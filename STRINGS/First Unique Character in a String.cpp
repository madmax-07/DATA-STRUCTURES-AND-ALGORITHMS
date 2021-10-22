class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>>freq(26);
        //initialise all pairs as -1,-1
        for(int i=0;i<26;i++){
            freq[i]={-1,-1};
        }
        
        for(int i=0;i<s.length();i++){
            int n=s[i]-'a';
            if(freq[n].first == -1)//unitialised until now
                freq[n]={i,1};//(index ,count)
            else 
                freq[n].second++;//increase the count
        }
        int index=INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i].first!=-1 and freq[i].second==1)//matlap string ka part h
                index=min(index,freq[i].first);
             
        }
        if(index!=INT_MAX)
        return index;
        else return -1;
        
    }
};
//TC:O(n)
//sc: O(1)
