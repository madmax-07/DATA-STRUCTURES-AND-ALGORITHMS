class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>occur;
        unordered_set<string>ban(banned.begin(),banned.end());
        int i=0;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        int n=paragraph.length();
        while(i<n){
            string str="";
            while(i<n and paragraph[i]>='a' and paragraph[i]<='z')
                str+=paragraph[i++];
            if(ban.find(str)==ban.end())
                occur[str]++;
            while(i<n and !isalnum(paragraph[i])) i++;
        }
        string ans="";
        int maxi=0;
        for(auto it:occur){
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }
        }
        return ans;
        
    }
};
