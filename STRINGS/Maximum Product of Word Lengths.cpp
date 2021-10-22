class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mp=0;
      
        for(int i=0;i<words.size();i++){
            //set frequency of all the charahters in string 1
            int freq[26]={0};
            string s1=words[i];
            for(int k=0;k<s1.length();k++){
                freq[s1[k]-'a']=1;
            }
            //no start checking for all words from i+1
            for(int j=i+1;j<words.size();j++){
                string s2=words[j];
                //check if there is any coomon charchters in s2 with s1
                int k;
                for(k=0;k<s2.length();k++)
                {if(freq[s2[k]-'a']==1)
                    break;} //matlap there is a common char
            if(k==s2.length()) //no common char found
            {int len=s1.length()*s2.length();
                mp=max(mp,len);
            }
            }
        }
        return mp;
        
    }
};
//tc:O(n^2)
