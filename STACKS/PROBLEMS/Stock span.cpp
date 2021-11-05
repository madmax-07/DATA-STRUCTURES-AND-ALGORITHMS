class StockSpanner {
public:
    stack<pair<int,int>>s;
    int id=0;
    
    StockSpanner() {
    }
    
    int next(int price) {
     id++;
        while(!s.empty() and s.top().first<=price){
            s.pop();
        }
        int ans;
        if(!s.empty()){
            ans=id-s.top().second;
        }
        else ans=id;
        s.push({price,id});
        return ans;
            }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
