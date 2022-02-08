/*Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
 

Constraints:

1 <= n <= 231 - 1
*/
class Solution {
public:
    /*consider n=6537421
 STEP 1: starting from the one's place we have to find the number breaks the increasing order of series (as we move towards                  right).This is our inflection-point (ip)
    -> ip==3 as 3<7>4>2>1
 STEP 2:Find the smallest number( from the one's place until ip-1) which is greater than ip(3 here) So that we can find ans
    ->no found =4 
    -> swap 3 with 4 to get n="65(4)7(3)21". 
    ## this step ensures we get the right number at the inflection point to get our ans
    
 STEP 3: Now in order to ensure the number above is just greater than the given number n
         We will sort the string from ip+1 until end
 65(4)[7321]->6541237
    
    */
  class Solution {
public:
    /*consider n=6537421
 STEP 1: starting from the one's place we have to find the number breaks the increasing order of series (as we move towards                  right).This is our inflection-point (ip)
    -> ip==3 as 3<7>4>2>1
 STEP 2:Find the smallest number( from the one's place until ip-1) which is greater than ip(3 here) So that we can find ans
    ->no found =4 
    -> swap 3 with 4 to get n="65(4)7(3)21". 
    ## this step ensures we get the right number at the inflection point to get our ans
    
 STEP 3: Now in order to ensure the number above is just greater than the given number n
         We will sort the string from ip+1 until end
 65(4)[7321]->6541237
    
    */
    int nextGreaterElement(int n) {
        string s=to_string(n);
        if(s.length()==1)
            return -1;
        //Step 1 : Find the index where we find the first inflection point(s[ip]<s[ip+1])
        int ip=s.length()-1;
         while(ip >0 and int(int(s[ip-1])>=s[ip]))
            ip--;
        //Now if ip==0 there is no inflection point in the series,all the charachters are in increasing order 
        if(ip==0)
            return -1;
        
    //Find the smallest charhter which is greater than s[ip]
        int j=s.length()-1;
        while(j>=ip and int(s[ip-1])>=int(s[j]))
            j--;
        
        swap(s[j],s[ip-1]);
    //STEP 3: sort from ip+1 to end since we hav eto make this smallest 
        sort(s.begin()+ip,s.end());
    //given that the number can be long long after swapping 
        long long ans=stoll(s); //stoll - converts string to Long Long int 
        if(ans>INT_MAX)
            return -1;
        return ans;
    }
};
//
