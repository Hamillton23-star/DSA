class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n=nums.size();
       int k=0,m=1;
       vector<int> result(n);
       for(int i=0;i<n;i++){
        if(nums[i]>0){
            result[k]=nums[i];
            k+=2;
        }
        else{
            result[m]=nums[i];
            m+=2;
        }
       }
       return result;
    }
};