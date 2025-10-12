class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
             adj[it].push_back(i);
            }
        }
        vector<int> indegree(n, 0);
        for (int i = 0; i <n; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i <n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();     
            ans.push_back(node); 
                 
            for (int neighbor : adj[node]) {
                indegree[neighbor]--; 
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};