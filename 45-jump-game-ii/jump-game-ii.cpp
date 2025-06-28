class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int jumps=0;
        int farthest=0;
        while(r<n-1){
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            jumps++;
            l=r+1;
            r=farthest;
        }
        return jumps;
    }
};