class Solution {
public:
 // bool isopp(int a ,int b){
 //       if(b<0 and a>0)
 //        return true;
 //     return false;
 //    }
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>s;
        for(int i=arr.size()-1;i>=0;i--){
            bool flag=0;
          while(!s.empty() and (arr[i]>0 and s.top()<0))
          {
             if(abs(s.top())==arr[i])
              {  s.pop();
               flag=1;
                break;
              }
            else if(abs(s.top())>abs(arr[i]))
            {  flag=1;
                break;
            }
             else 
                 s.pop();
          }
            if(!flag)
                s.push(arr[i]);
                
         }
        vector<int>ans;
              while(!s.empty()){
                  ans.push_back(s.top());
                  s.pop();
              }
        return ans;
    }
          
};
