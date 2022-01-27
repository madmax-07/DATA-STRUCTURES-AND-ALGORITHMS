class Solution {
public:
    class maxi{
        public:
        int max1;
        int max2;
        int max3;
    }obj1;
    class mini{
        public:
        int min1;
        int min2;
    }obj2;
    
    int maximumProduct(vector<int>& nums) {
        obj1.max1=obj1.max2=obj1.max3=-1001;
        obj2.min1=obj2.min2=1001;
        //finding the maximum 3 and min 2 
        
        for(int i=0;i<nums.size();i++){
         if(nums[i]>obj1.max1)
         { obj1.max3=obj1.max2;
           obj1.max2=obj1.max1;
           obj1.max1=nums[i];
         }
        else if(nums[i]>obj1.max2)
        {   obj1.max3= obj1.max2;
            obj1.max2=nums[i];
        }
        else if(nums[i]>obj1.max3)
        {
            obj1.max3=nums[i];
        }
        if(nums[i]<obj2.min1)
        {  obj2.min2=obj2.min1;
        obj2.min1=nums[i];
        }
        else if(nums[i]<obj2.min2)
            obj2.min2=nums[i];
        
        }
        
          int p1=obj1.max1*obj1.max2*obj1.max3;
          int p2=obj2.min1*obj2.min2*obj1.max1;
        return max(p1,p2);
    }
};
            
      //  int n=nums.size();
  //       //sort(nums.begin(),nums.end());
  //       int p1,p2,p3,p4;
  //     //all+ve & all-ve 
  //      p1=nums[n-1]*nums[n-2]*nums[n-3];
  //  // -5,-4,10,20,30 -p4 
  // //  p2=nums[0]*nums[1]*nums[2];
  //   // -10,-9
  //       p3=nums[0]*nums[1]*nums[n-1];
  //     //  p4=nums[0]*nums[n-1]*nums[n-2];
  //       return max(p1,p3);
  //    O(nlogn)
  //    O(n)
  //        //biggest 3
  //        //smallest 2
    

