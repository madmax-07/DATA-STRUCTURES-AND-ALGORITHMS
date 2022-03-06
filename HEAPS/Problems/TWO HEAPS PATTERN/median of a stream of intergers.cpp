class MedianFinder {
    //for max heap the left one 
    priority_queue<int>pq1;
    //for min heap right one 
    priority_queue<int,vector<int>,greater<int>>pq2;
    double median;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    //case 1: when both pq's are empty 
        if(pq1.empty() and pq2.empty()){
            pq1.push(num);
            median=pq1.top();
            return;
        }
        if(pq1.size()>pq2.size()){
            if(num>median){
                pq2.push(num);
            }
            else {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
            
            median=(pq1.top()+pq2.top())/2.0;
            return;
        }
        else if(pq1.size()==pq2.size()){
            if(num<median){
                pq1.push(num);
                median=pq1.top();
                return;
            }
            else {
                pq2.push(num);
                median=pq2.top();
                return;
                }
        }
    
        else { //the right queue is bigger than the left 
            if(num>median){
                pq2.push(num);
                pq1.push(pq2.top());
                pq2.pop();
             }
            else pq1.push(num);
            median=(pq1.top()+pq2.top())/2.0;
            return;
            }
            
        }
           
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
