class Solution {
public:
    map<pair<int, long long>, int> dp;

    int solve(int i, long long prev, vector<int>& arr1, vector<int>& arr2) {
        if (i == arr1.size()) return 0;

        if (dp.count({i, prev})) return dp[{i, prev}];

        int res = INT_MAX;

      
        if (arr1[i] > prev) {
            res = solve(i + 1, arr1[i], arr1, arr2);
        }

      
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            long long replaced = *it;
            int option = solve(i + 1, replaced, arr1, arr2);
            if (option != INT_MAX) res = min(res, 1 + option);
        }

        return dp[{i, prev}] = res;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ans = solve(0, LLONG_MIN, arr1, arr2);  // LLONG_MIN for safety
        return (ans >= 2e4) ? -1 : ans;
    }
};
