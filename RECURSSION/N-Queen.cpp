class Solution {
public:
bool isSafe(vector<vector<int>>&board,int r,int c,int n){
    //upper col
    for(int i=r-1;i>=0;i--){
        if(board[i][c]==1)
            return false;
    }
    //right diag
    for(int i=r-1,j=c+1;i>=0 and j<n;i--,j++){
        if(board[i][j]==1)
            return false;
    }
    //left diag
    for(int i=r-1,j=c-1;i>=0 and j>=0;i--,j--)
    {
        if(board[i][j]==1)
         return false;
    }
        return true;
}

    vector<vector<string>>ans;
   void help(int r,int n,vector<vector<int>>&board){
        if(r==n){
            vector<string>v;
            for(int i=0;i<n;i++){
                string str="";
                for(int j=0;j<n;j++){
                    if(board[i][j]==0)
                        str.push_back('.');
                     else if(board[i][j]==1)
                         str.push_back('Q');
                }
                v.push_back(str);
            }
            ans.push_back(v);
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,r,i,n)){
                board[r][i]=1;
                help(r+1,n,board);
                board[r][i]=0;
            }
        }
   }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        help(0,n,board);
        return ans;
    }
    
};
