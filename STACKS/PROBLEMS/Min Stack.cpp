class MinStack {
public:
    stack<int>alldata;
    stack<int>mindata;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mindata.empty())
            mindata.push(val);
        else if(mindata.top()>=val)
            mindata.push(val);
        alldata.push(val);
        return;
    }
    
    void pop() {
        if(!mindata.empty() and alldata.top()==mindata.top())
            mindata.pop();
        if(!alldata.empty())
                alldata.pop();
        return;
    }
    
    int top() {
    if(!alldata.empty())
        return alldata.top();
        return -1;
    }
    
    int getMin() {
        if(!mindata.empty())
            return mindata.top();
        return 0;    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
