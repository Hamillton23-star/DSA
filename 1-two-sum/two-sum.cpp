class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>vcc;
        int n=nums.size();
        for(int i=0;i<n;i++){
        vcc[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int complement=target-nums[i];
            if(vcc.count(complement) && vcc[complement] !=i){
                return{i,vcc[complement]};
            }
            }
          return{};
    }
};