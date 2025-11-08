class Solution {
public:
      int Subarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        int nicecnt=0;
        while(r<n){
            if(nums[r]%2==1)cnt++;
            while(cnt>k){
                if(nums[l]%2==1)cnt=cnt-1;
                l++;
            }
            nicecnt+=r-l+1;
            r++;
        }
      return nicecnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
      return Subarrays(nums,k)-Subarrays(nums,k-1);
    }
};