class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        map<char,pair<int,int> >mp;
        //step 1 prepare a map
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]={i,i};
            }
            else if(mp.find(s[i])!=mp.end())
            { mp[s[i]].second=i;
            }
        }
        /*
        for(auto it:mp){
            cout<<it.first<<":"<<it.second.first<<it.second.second<<endl;
        }
        */
        vector<pair<int,int> >v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        //step 2: Sort map according to first index in pair 
        sort(v.begin(),v.end());
        //step 3: Traverse the map  
        int flag=0;
        int si;
        int key;
        for(auto it:v){
            if(!flag){
                si=it.first;
                key=it.second;
                flag=1;
            }
            else if(it.first<key){
            key=(it.second>key)?(it.second):key;
            }
            else {
                ans.push_back(key-si+1);
                si=key+1;
                key=it.second;
            }
            }
        ans.push_back(key-si+1);
        return ans;
    }
};
