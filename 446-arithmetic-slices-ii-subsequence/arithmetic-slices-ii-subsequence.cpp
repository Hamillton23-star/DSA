class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long result = 0;
        vector<unordered_map<long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - (long)nums[j];


                int count = dp[j].count(diff) ? dp[j][diff] : 0;

                dp[i][diff] += count + 1;

                result += count;
            }
        }

        return (int)result;
    }
};
