class Solution {
public:
    int convert(string s){
        reverse(s.begin(),s.end());
        int num=0;
        for(int i=0;i<s.length();i++){
            num+=pow(2,i)*(s[i]-'0');
        }
        return num;
    } 
    vector<string>genrate(int n){
        if(n==1){
           vector<string>v;
            v.push_back("0");
            v.push_back("1");
            return v;
        }
        vector<string>ans;
        vector<string>v=genrate(n-1);
        for(int i=0;i<v.size();i++){
            string s='0'+v[i];
            ans.push_back(s);
        }
        for(int i=v.size()-1;i>=0;i--){
            string s='1'+v[i];
            ans.push_back(s);
        }
        return ans;
    }
    vector<int> grayCode(int n) {
         vector<string>ans=genrate(n);
        vector<int>fa;
        for(int i=0;i<ans.size();i++){
            int num=convert(ans[i]);
            fa.push_back(num);
        }
        return fa;
    }
};
//watch pep video for logic 
