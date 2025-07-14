class Solution {
public:
    int solve(int ind, int prev, string& s, vector<vector<int>>& dp) {
        if (ind == s.size()) return 0;

        if (dp[ind][prev] != -1) return dp[ind][prev];

        int flip = 1e9, notflip = 1e9;
        int curr = s[ind] - '0'; 
      
        if (curr >= prev) { 
            notflip = solve(ind + 1, curr, s, dp);
        }

       
        flip = 1 + solve(ind + 1, prev, s, dp); 
        return dp[ind][prev] = min(flip, notflip);
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, s, dp); 
    }
};
