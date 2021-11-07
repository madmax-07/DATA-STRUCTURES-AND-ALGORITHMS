class Solution {
public:
    vector<string>mp={"" ,"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void help(string digits,vector<string>&ans,string s,int i){
        //base case
        if(i==digits.length()){
            ans.push_back(s);
            return;
        }
        int n=digits[i]-'0';
        string str=mp[n];
        for(int id=0;id<str.length();id++){
            s+=str[id];
            help(digits,ans,s,i+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        if(digits.length()==0)
            return ans;
        help(digits,ans,"",0);
        return ans;
    }
};
