class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        if(n==0)
            return 1;
        double ans=myPow(x,abs(n/2));
        ans*=ans;
        if(n%2!=0){
            ans=x*ans;
        }
        if(n<0){
            return (1/ans);
        }
        else 
            return ans;
        
    }
};
