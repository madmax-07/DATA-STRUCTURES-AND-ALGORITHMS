/*
You are given a number n representing number of stairs in a staircase.
2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
3. Complete the body of getStairPaths function - without changing signature - to get the list of all paths that can be used to climb the staircase up.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Sample Input

3

Sample Output

[111, 12, 21, 3]
*/
void help(int n,vector<string>&ans,string path){
    if(n==0){
        ans.push_back(path);
        return;
    }
    if(n<0)
    return;
    for(int i=1;i<=3;i++){
        if(n-i>=0){
        path+=to_string(i);
        help(n-i,ans,path);
        path.pop_back();
    }
}
}
