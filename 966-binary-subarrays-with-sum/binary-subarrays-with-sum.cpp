class Solution {
public:
    int minefunc(vector<int>& nums, int goal){
      int n=nums.size();
      int sum=0;
      if(goal<0) return 0;
      int l=0,count=0,r=0;

      while(r<n){
         sum+=nums[r];
      

         while(sum>goal){
            sum=sum-nums[l];
            l++;
         }
        count+= r-l+1;
      r++;
      }  
      return count;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
     return minefunc(nums,goal)-minefunc(nums,goal-1);
    }
};