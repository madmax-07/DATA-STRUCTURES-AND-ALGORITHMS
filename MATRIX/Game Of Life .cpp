class Solution {

  public:
    int dx[8]={-1,1,0,0,-1,1,-1,1};
    int dy[8]={0,0,-1,1,-1,1,1,-1};
    
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
     for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
             int live=0;
             //calculate neighbours for a[i][j]
             for(int k=0;k<8;k++){
                 if((i+dx[k]>=0 and i+dx[k]<r) and (j+dy[k]>=0 and j+dy[k]<c))
                 {
                     if(board[i+dx[k]][j+dy[k]]==1||board[i+dx[k]][j+dy[k]]==3)
                         live++;
                 }
             }
             //end calcultaing ngbr
             if(board[i][j] and (live<2 || live>3))
                 board[i][j]=3;//0 kardo phele se 1 tha and to remeber phele 1 tha we use 3 as a flag marker
             else if(board[i][j]==0 and live==3)
                 board[i][j]=4; //1 kardo phele 0 tha and to remember phele 0 tha we use 4 as a flag marker
         }
     }
      //update the chaged states 
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                if(board[i][j]==3)
                    board[i][j]=0;
                else if(board[i][j]==4)
                    board[i][j]=1;
                
        }
    }
};
