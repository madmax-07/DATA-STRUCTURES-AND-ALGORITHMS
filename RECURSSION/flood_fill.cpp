class Solution {
public:
    int visted[50][50]={0};
    void fill(vector<vector<int>>& image,int i,int j, int val,int newcol){
        if(i<0||i==image.size()||j<0||j==image[0].size()||image[i][j]!=val||visted[i][j]){
            return;
        }
        visted[i][j]=true;
        image[i][j]=newcol;
        fill(image,i-1,j,val,newcol);
        fill(image,i,j-1,val,newcol);
        fill(image,i+1,j,val,newcol);
        fill(image,i,j+1,val,newcol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r=image.size();
        int c=image[0].size();
        int val=image[sr][sc];
        fill(image,sr,sc,val,newColor);
        return image;
        
    }
};
