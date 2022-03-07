class Solution {
public:
    void help(int i,int j,int r,int c,vector<vector<int>>& grid){
        if(i<0||i==r||j<0||j==c||grid[i][j]==0||grid[i][j]==-1)
            return;
        grid[i][j]=-1;
        help(i-1,j,r,c,grid);
        help(i,j+1,r,c,grid);
        help(i+1,j,r,c,grid);
        help(i,j-1,r,c,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int dir=1;
        if(dir%5==1){
            int i=0;
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    help(i,j,r,c,grid);
            }
            dir++;
        }
         if(dir%5==2){
            int j=c-1;
            for(int i=0;i<r;i++){
                if(grid[i][j]==1)
                    help(i,j,r,c,grid);
            }
            dir++;
        }
         if(dir%5==3){
            int i=r-1;
            for(int j=c-1;j>=0;j--){
                if(grid[i][j]==1)
                    help(i,j,r,c,grid);
            }
            dir++;
        }
         if(dir%5==4){
            int j=0;
            for(int i=r-1;i>=0;i--){
                if(grid[i][j]==1)
                    help(i,j,r,c,grid);
            }
            dir++;
        }
    
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};
