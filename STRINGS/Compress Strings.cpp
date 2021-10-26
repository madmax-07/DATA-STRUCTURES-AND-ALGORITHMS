class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int i=0;
        while(i<chars.size()){
            int j=i+1;
            while(j<chars.size()and chars[j]==chars[i]){
                j++;
            }
            int count=j-i;
            s+=chars[i];
            if(count>1)
            s+=to_string(count);
            i=j;
        }
        chars.clear();
    for(int i=0;i<s.length();i++){
        chars.push_back(s[i]);
    }
        return chars.size();
            
        }
        
    
};
