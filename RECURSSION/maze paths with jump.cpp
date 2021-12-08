
/* QUESTION
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Constraints

0 <= n <= 10 0 <= m <= 10

Format

Input

A number n
A number m

Output

Contents of the arraylist containing paths as shown in sample output

Example

Sample Input

2
2

Sample Output

[h1v1, v1h1, d1]
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;
void help(int sr,int sc,int dr,int dc,vector<string>&ans,string path){
    //base case
    if(sr<0||sr>dr||sc<0||sc>dc)
    return;
    if(sr==dr and sc==dc)
     { ans.push_back(path);
        return;
    }
    //horizontal{
    
    for(int jump=1;sc+jump<=dc;jump++){
        path+="h";
        path+=to_string(jump);

        help(sr,sc+jump,dr,dc,ans,path);
        path.pop_back();
        path.pop_back();
    }
    
    //verticle
    
    for(int jump=1;sr+jump<=dr;jump++){
        path+="v";
        path+=to_string(jump);
    help(sr+jump,sc,dr,dc,ans,path);
    path.pop_back();
    path.pop_back();
    
    }
    //diagnol
    
    for(int jump=1;sr+jump<=dr and sc+jump<=dc;jump++)
    {   path+="d";
        path+=to_string(jump);
    
        help(sr+jump,sc+jump,dr,dc,ans,path);
    
    path.pop_back();
    path.pop_back();
    
    }
}

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    //Write your code here
    vector<string>ans;
    help(sr,sc,dr,dc,ans,"");
    return ans;
    }
    
void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = get_maze_paths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
