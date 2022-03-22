/*
22. Generate Parentheses
Medium

12128

474

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
class Solution {
public:
    void help(string str,int open,int close,int n,vector<string>&ans){
        
        if(open==n and close==n){
            ans.push_back(str);
            return;
        }
        
        if(open<n){
            str+='(';
            help(str,open+1,close,n,ans);
            str.pop_back();
        }
        if(close<open and close<n)
        { str+=')';
            help(str,open,close+1,n,ans);
            str.pop_back();
        }
    }
        
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string>ans;
        help("",open,close,n,ans);
        return ans;
        
    }
};
