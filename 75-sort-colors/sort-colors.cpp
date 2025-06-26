class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt1++;
             if(nums[i]==1)cnt2++;
              if(nums[i]==2)cnt3++;
        }
        int k=0;
      while(cnt1){
        nums[k]=0;
        k++;
        cnt1--;
      }
      while(cnt2){
        nums[k]=1;
        k++;
        cnt2--;
      }
      while(cnt3){
        nums[k]=2;
        k++;
        cnt3--;
      }
      
    }

};