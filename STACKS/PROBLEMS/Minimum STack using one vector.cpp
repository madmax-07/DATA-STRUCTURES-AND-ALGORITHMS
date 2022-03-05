class MinStack {
public:
    stack<pair<long ,long >>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
            return;
        }
        if(val>=s.top().second){
            s.push({val,s.top().second});
            return;
        
        }
        else{
            long long min=s.top().second;
            long long x=val+(val-min);
            s.push({x,val});
            return;
            }
    }
    
    void pop() {
      if(!s.empty())
          s.pop();
    }
    
    int top() {
        if(s.empty())
            return -1;
        if(s.top().first<s.top().second)
            return s.top().second;
        else return s.top().first;
    }
    
    long long  getMin() {
        if(s.empty())
            return  0;
         return s.top().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
