//note that the approachh used has a time complecity of O(N^2) and space compexity of O(1)
// the idea behind the solution is to find a center and move rightward and leftwrds to find a palindromic length 
class Solution {
public:
    string longestPalindrome(string s) {
        int len=0,start=0,end=0,len1=0,len2=0, mlen=0;
        for(int i=0;i<s.length();i++){
            len1=is_palindrome(s,i,i);
            len2=is_palindrome(s,i,i+1);
            len=max(len1,len2);
            if(len>mlen){
                start=i-(len-1)/2;
                end=i+len/2;
                mlen=(end-start)+1;
            }}
        return s.substr(start,mlen);
        }
    int is_palindrome(string s,int i,int j){
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            i--;
            j++;
        }
        return j-1-i; }

};