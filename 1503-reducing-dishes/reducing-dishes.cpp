class Solution {
public:
    int solve(int ind, int time, vector<int>& satisfaction, vector<vector<int>>& dp) {
        int n = satisfaction.size();
        if (ind == n) return 0;

        if (dp[ind][time] != -1) return dp[ind][time];

        int take = satisfaction[ind] * (time + 1) + solve(ind + 1, time + 1, satisfaction, dp);
      
        int nottake = solve(ind + 1, time, satisfaction, dp);

        return dp[ind][time] = max(take, nottake);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end()); // Important!
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, satisfaction, dp);
    }
};

