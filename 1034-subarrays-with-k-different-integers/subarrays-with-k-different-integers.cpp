class Solution {
public:
     int subarray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        map<int,int> mpp;
        int mxcnt=0;
        while(r<n){
            mpp[nums[r]]++;

         while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
           mxcnt=mxcnt+(r-l+1);
            r++;
        }
      return mxcnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return subarray(nums,k)-subarray(nums,k-1);
    }
};