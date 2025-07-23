class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        
        priority_queue<pair<double, int>> pq; 
        vector<double> dist(n, 0.0); 

        dist[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end) return prob; 

            for (auto& [neighbor, edgeProb] : adj[node]) {
                double newProb = prob * edgeProb;
                if (newProb > dist[neighbor]) {
                    dist[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0; 
    }
};
