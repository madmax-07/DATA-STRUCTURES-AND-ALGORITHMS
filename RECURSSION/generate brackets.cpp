class Solution {
public:
    void create_brackets(string s,vector<string>&ans,int n,int len,int i,int open,int close){
        //base condition 
        if(i==len){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+='(';
            create_brackets(s,ans,n,len,i+1,open+1,close);
            s.pop_back();
        }
        if(close<open){
            s+=')';
            create_brackets(s,ans,n,len,i+1,open,close+1);
            s.pop_back();
        }
    }
        
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        create_brackets("",ans,n,2*n,0,0,0);
        return ans;
        
    }
};
