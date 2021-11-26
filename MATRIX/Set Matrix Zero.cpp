/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
//solution 1 : tc O(nxm) and sc=O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row(matrix.size(),-1); //row
        vector<int>col(matrix[0].size(),-1); //col
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(row[i]==0||col[j]==0)
                    matrix[i][j]=0;
            }
        }
                    
            }
        

};
//solution 2
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        bool row=false,col=false;
        for(int i=0;i<c;i++){
            if(matrix[0][i]==0)
                row=true;
        }
        for(int i=0;i<r;i++){
            if(matrix[i][0]==0)
                col=true;
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==0)
                {   matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
     for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<c;i++){
                if(row)
                matrix[0][i]=0;
        }
         for(int i=0;i<r;i++){
                if(col)
                matrix[i][0]=0;
            }
            
        }
  /*tc:O(r*c)
  Sc:O(1)
  */
  
};
