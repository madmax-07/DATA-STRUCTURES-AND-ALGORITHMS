/*question link:https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
Approach :
A brute force solution for this problem is to do a postorder traversal of a binary search tree and take absolute difference of each element find the node having minimum absolute difference with given target value K in linear time.

An efficient solution for this problem is to take advantage of characteristics of BST. Here is the algorithm to solve this problem :

If target value K is present in given BST, then it’s the node having minimum absolute difference.
If target value K is less than the value of current node then move to the left child.
If target value K is greater than the value of current node then move to the right child.
basically hume diffrence (val-K) ki value minimise karne h that means ki dono numbers a and b should be approaching/close to each other
*/
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	int diff=INT_MAX;
	 void calculate_diff(Node*root,int k){
	    if(root==NULL)
	    return;
	    diff=min(abs(root->data-k),diff);
	    if(root->data>k)
	    { calculate_diff(root->left,k);
	    }
	    else if(root->data<k)
	    calculate_diff(root->right,k);
	}
    int minDiff(Node *root, int k)
    { calculate_diff(root,k);
      return diff;
        //Your code here
    }
};
//tc:o(logn) in best case and o(n) in worst case
// sc:O(logn) in bestcase and o(n) in worst case 
