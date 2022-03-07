//Connected Components Pattern
class Solution {
public:
    int color_help(int i,int j,int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visted,int x){
        if(i<0||i==r||j<0||j==c|| abs(grid[i][j])!=x){
            return 0;
        }
        else if(visted[i][j] and abs(grid[i][j])==x)
            return 1;
        visted[i][j]=1;
        int count=0;
        count+=color_help(i-1,j,r,c,grid,visted,x);
        count+=color_help(i,j+1,r,c,grid,visted,x);
        count+=color_help(i+1,j,r,c,grid,visted,x);
        count+=color_help(i,j-1,r,c,grid,visted,x);
        if(count<4)
            grid[i][j]=-1*grid[i][j];
        return 1;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>visted(r,vector<int>(c,0));
        color_help(row,col,r,c,grid,visted,grid[row][col]);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]<0)
                    grid[i][j]=color;
            }
        }
        return grid;
        
    }
};
