/*
Problem Statement
Given an array of distinct integers, find all the pairs having positive value and negative value of a number that exists in the array. Return the pairs in any order.
Note:
The pair consists of equal absolute values, one being positive and another negative.

Return an empty array, if no such pair exists.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next ‘2T’ lines represent the ‘T’ test cases.

The first line of each test case contains an integer ‘N’ denoting the number of integers in the array. 

The second line of each test case contains ‘N’ space-separated integers which denote the elements of the array.
Output Format:
For each test case, print all pairs with equal absolute value with one being positive and another negative. 
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 50
1 <= N <= 10^4
-10^5 <= A[i] <= 10^5

Time Limit: 1 second
Sample Input 1:
2
2
-2 2
2
1 2
Sample Output 1:
-2 2
Explanation For Sample Output 1:
Test case 1:
In the first test case, we can see that the absolute values of -2 and 2 are the same. But their signs are different(positive and negative). So that’s our answer. 

Test case 2:
There is no number present in the array with both positive and negative values. 
Sample Input 2:
2
6
1 -3 2 3 6 -1
8
4 8 9 -4 1 -1 -8 -9
Sample Output 2:
-1 1 -3 3
-1 1 -4 4 -8 8 -9 9
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> pairs(vector<int> &arr, int n) {
    // Write your code here#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> pairs(vector<int> &arr, int n) {
    // Write your code here
	vector<pair<int,int>>ans;
	unordered_map<int,int>mp;
	for(int i=0;i<arr.size();i++){
		if(mp.find(abs(arr[i]))!=mp.end()){
			ans.push_back({-1*abs(arr[i]),abs(arr[i])});
		}
		else mp[abs(arr[i])]=1;
	}
	return ans;
}
	vector<pair<int,int>>ans;
	unordered_map<int,int>mp;
	for(int i=0;i<arr.size();i++){
		if(mp.find(abs(arr[i]))!=mp.end()){
			ans.push_back({-1*abs(arr[i]),abs(arr[i])});
		}
		else mp[abs(arr[i])]=1;
	}
	return ans;
}
