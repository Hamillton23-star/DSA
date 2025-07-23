class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        // Graph: node -> [(neighbor, time)]
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        // minFee[node][time] = minimum fee to reach node at exact time
        vector<vector<int>> minFee(n, vector<int>(maxTime + 1, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        // tuple: (totalCost, node, time)
        pq.push({passingFees[0], 0, 0});
        minFee[0][0] = passingFees[0];

        while (!pq.empty()) {
            auto [cost, u, time] = pq.top(); pq.pop();

            if (u == n - 1) return cost;

            for (auto& [v, t] : adj[u]) {
                if (time + t <= maxTime) {
                    int newCost = cost + passingFees[v];
                    if (newCost < minFee[v][time + t]) {
                        minFee[v][time + t] = newCost;
                        pq.push({newCost, v, time + t});
                    }
                }
            }
        }

        return -1;
    }
};
