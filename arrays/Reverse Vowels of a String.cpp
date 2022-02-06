class Solution {
public:
    string reverseVowels(string a) {
        int i=0,j=a.length()-1;
        map<char,int>mp;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        while(i<=j){
        if(mp.find(a[i])!=mp.end() and mp.find(a[j])!=mp.end())
            {   swap(a[i],a[j]);
                i++;
                j--;
            }
        else if(mp.find(a[i])==mp.end() and mp.find(a[j])==mp.end())
            {
            i++;
            j--;
            }
        else if(mp.find(a[i])!=mp.end() and mp.find(a[j])==mp.end())
         j--;
        else 
            i++;
        }
        return a;
        
    }
};
