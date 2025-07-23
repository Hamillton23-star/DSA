class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        pq.push({0, 0, 0}); 
        
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [obs, row, col] = pq.top(); pq.pop();
            
            if (vis[row][col]) continue;
            vis[row][col] = 1;

            if (row == n - 1 && col == m - 1) return obs;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol]) {
                    if (grid[nrow][ncol] == 0) {
                        pq.push({obs, nrow, ncol});
                    } else {
                        pq.push({obs + 1, nrow, ncol});
                    }
                }
            }
        }
        
        return -1;
    }
};
