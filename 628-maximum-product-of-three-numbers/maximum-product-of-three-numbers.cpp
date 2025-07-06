class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        bool swapped;

        // Bubble sort in increasing order
        for (int i = 0; i < n; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }

       
        int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3]; 
        int product2 = nums[0] * nums[1] * nums[n - 1];        

        return max(product1, product2);
    }
};
