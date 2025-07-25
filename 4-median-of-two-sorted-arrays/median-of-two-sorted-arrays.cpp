class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int total=m+n;
        int count=0;
        int i=0,j=0;
        int curr=0,prev=0;

        while(count<=total/2){
            prev=curr;
          if(i<n && (j>=m || (nums1[i]<=nums2[j]))){
           curr=nums1[i++];
          }
          else{
          curr=nums2[j++];
          }
             count++;
        }
        if(total % 2 ==0){
            return (prev+curr)/2.0;
        }
        return curr;
    }
};