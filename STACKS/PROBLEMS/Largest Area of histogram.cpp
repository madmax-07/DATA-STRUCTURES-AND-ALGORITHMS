class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        //step 1: find the next smallest elemnt on the right side
        vector<int>right(n);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty())
                right[i]=n;
            
            else if(!st.empty())
            {right[i]=st.top().second;}
            st.push({heights[i],i});
        }
        while(!st.empty())st.pop();
        vector<int>left(n);
        for(int i=0;i<n;i++){
         while(!st.empty() and st.top().first>=heights[i])
            st.pop();
            
            if(st.empty())
                left[i]=-1;
            else if(!st.empty()){
                left[i]=st.top().second;
            }
            st.push({heights[i],i});
        }
        while(!st.empty())st.pop();
        int max_area=INT_MIN;
        for(int i=0;i<n;i++){
            int width=(right[i]-i) + (i-left[i])-1;
            int area=heights[i]*width;
            max_area=max(area,max_area);
        }
        return max_area;
        //Step 2: find the next smallest elemnt on the left side
        
        
    }
};
