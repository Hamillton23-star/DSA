class Disjoint {
public:
    vector<int> parent, rank, size;
    Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unionbysize(int u, int v) {
        int up = find(u), uq = find(v);
        if (up == uq) return;
        if (size[up] < size[uq]) {
            parent[up] = uq;
            size[uq] += size[up];
        } else {
            parent[uq] = up;
            size[up] += size[uq];
        }
    }

    void unionbyrank(int u, int v) {
        int up = find(u), uq = find(v);
        if (up == uq) return;
        if (rank[up] < rank[uq]) {
            parent[up] = uq;
        } else if (rank[up] > rank[uq]) {
            parent[uq] = up;
        } else {
            parent[uq] = up;
            rank[up]++;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges;

        // 1. Build all edges with distances
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

       
        sort(edges.begin(), edges.end());

       
        Disjoint dsu(n);
        int mstCost = 0;
        int count = 0;

        for (auto [wt, u, v] : edges) {
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unionbysize(u, v);
                mstCost += wt;
                count++;
                if (count == n - 1) break;
            }
        }

        return mstCost;
    }
};
