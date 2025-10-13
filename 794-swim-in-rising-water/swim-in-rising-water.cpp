class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == n - 1)
                return time;

            for (int k = 0; k < 4; k++) {
                int newr = row + drow[k];
                int newc = col + dcol[k];

                if (newr >= 0 && newr < n && newc >= 0 && newc < n && !vis[newr][newc]) {
                    vis[newr][newc] = 1;
                    pq.push({max(time, grid[newr][newc]), {newr, newc}});
                }
            }
        }
        return -1; // Should never reach here if the input is valid.
    }
};
