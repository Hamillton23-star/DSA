class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
        int ans=0;
         
        for(int i=0;i<=n;i++){
          xor1=xor1^i;
        }
        for(int i=0;i<n;i++){
          ans=ans^nums[i];
        }
        return ans^xor1;
    }
};