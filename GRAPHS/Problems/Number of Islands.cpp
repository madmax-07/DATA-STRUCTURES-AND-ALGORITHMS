class Solution {
public:
     void find_connected(vector<vector<char>>& a,int i,int j){
         if(i<0 ||j<0||i>=a.size()||j>=a[0].size()||a[i][j]=='0')
             return;
         
         a[i][j]='0'; //marking the land visted by flipping the bits  from 0 to 1
         find_connected(a,i-1,j);
         find_connected(a,i+1,j);
         find_connected(a,i,j-1);
         find_connected(a,i,j+1);
         
}
    int numIslands(vector<vector<char>>& a) {
        //basically we have to find the connected components for the graphs which will give us the island
        int count=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]=='1'){
                    find_connected(a,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
