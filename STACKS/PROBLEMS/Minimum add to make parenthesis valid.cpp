class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="")
            return 0;
        stack<char>st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {if(st.empty())
                count++;
             else st.pop();
            }
        }
        count+=st.size();
        return count;
        
    }
};
