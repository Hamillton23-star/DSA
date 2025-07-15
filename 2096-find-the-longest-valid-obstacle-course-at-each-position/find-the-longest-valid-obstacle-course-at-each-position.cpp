class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans;
        vector<int> mono;

        for (int i = 0; i < n; ++i) {
            int idx = upper_bound(mono.begin(), mono.end(), obstacles[i]) - mono.begin();

            if (idx == mono.size()) {
                mono.push_back(obstacles[i]);
            } else {
                mono[idx] = obstacles[i];
            }

            ans.push_back(idx + 1);
        }

        return ans;
    }
};
