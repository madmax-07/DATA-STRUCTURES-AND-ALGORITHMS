class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.length()<name.length())
            return false;
        int curr=0,prev=0,i=0;
        while(i<typed.length() && curr<name.length()){
            if(typed[i]==name[curr])
            {prev=curr;
             curr++;
             i++;
            }
            else if(typed[i]!=name[curr] && typed[i]==name[prev])
            {
                while(i<typed.length() and typed[i]==name[prev])
                    i++;
            }
        
        else if(typed[i]!=name[curr])
            return false;
        }
        while(i<typed.length() and name[prev]==typed[i])
            i++;
        if(i==typed.length() and curr==name.length())
            return true;
        return false;
    }
};
