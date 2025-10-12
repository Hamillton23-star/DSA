class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>> adj(n);
      for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
      }
        
       vector<int> cost(n,1e9);
       cost[src]=0;
       queue<pair<int,pair<int,int>>> pq;
       pq.push({0,{src,0}});

       while(!pq.empty()){
        auto it=pq.front();
        int stops=it.first;
        int place=it.second.first;
        int price=it.second.second;
        pq.pop();
         if(stops>k)continue;
        for(auto it: adj[place]){
            int price2=it.second;
            int adjnode=it.first;
            if(price2+price<cost[adjnode]){
                cost[adjnode]=price+price2;
              pq.push({stops+1,{adjnode,cost[adjnode]}});
            }
        }
       }
       return (cost[dst]==1e9) ? -1: cost[dst]; 
    }
};