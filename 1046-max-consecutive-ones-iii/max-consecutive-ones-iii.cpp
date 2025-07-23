class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int n=nums.size();

      int l=0,r=0;
      int cnt=0,maxi=0;
      while(r<n){
        if(nums[r]!=1)cnt++;
         while(cnt>k){
            if(nums[l]!=1)cnt--;
            l++;
         }
        maxi=max(maxi,r-l+1);
        r++;
      }
      return maxi;
    }
};