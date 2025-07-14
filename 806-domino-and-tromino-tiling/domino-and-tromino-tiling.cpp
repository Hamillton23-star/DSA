class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int ind, vector<int>& dp) {
        if (ind == 0) return 1; 
        if (ind == 1) return 1;
        if (ind == 2) return 2;
        if (ind == 3) return 5;

        if (dp[ind] != -1) return dp[ind];

        return dp[ind] = ((2LL * solve(ind - 1, dp)) % MOD + solve(ind - 3, dp)) % MOD;
    }

    int numTilings(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
