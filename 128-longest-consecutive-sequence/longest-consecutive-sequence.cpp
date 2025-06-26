class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        int len=1;
        int maxi=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]+1==nums[i+1]){
            len++;
            maxi=max(maxi,len);
            }
            else if(nums[i]==nums[i+1]){
                continue;
            }
            else{
                len=1;
            }
        }
        return maxi;
    }
};