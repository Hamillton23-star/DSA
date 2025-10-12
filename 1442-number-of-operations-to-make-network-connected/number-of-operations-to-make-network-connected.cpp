class DisjointSet{
public:
vector<int> par,rank,size;
    
DisjointSet(int n){
    par.resize(n + 1);
    rank.resize(n + 1, 0);
    size.resize(n + 1, 1);

    for(int i = 0; i <= n; i++){
        par[i] = i;
    }
}

int findparent(int node){
    if(node == par[node]) return node;
    return par[node] = findparent(par[node]);
}

void unionbyrank(int u, int v){
    int ulp_u = findparent(u);
    int ulp_v = findparent(v);
     
    if(ulp_u == ulp_v) return;

    if(rank[ulp_u] < rank[ulp_v]){
        par[ulp_u] = ulp_v;
    }
    else if(rank[ulp_v] < rank[ulp_u]){
        par[ulp_v] = ulp_u;
    }
    else{
        par[ulp_u] = ulp_v;
        rank[ulp_v]++;
    }
}

void unionbysize(int u, int v){
    int ulp_u = findparent(u);
    int ulp_v = findparent(v);
     
    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
        par[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else {
        par[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
    int extra_cables = 0;
    DisjointSet ds(n);
    
    for(auto it : connections){
        int node1 = it[0];
        int node2 = it[1];
        
        if(ds.findparent(node1) != ds.findparent(node2)){
            ds.unionbysize(node1, node2);
        }
        else{
            extra_cables++;
        }
    }

    int connected_components = 0;
    for(int i = 0; i < n; i++){
        
        if(ds.par[i] == i){
            connected_components++;
        }
    }

    int required_cables = connected_components - 1;
    
    if(extra_cables >= required_cables){
        return required_cables;
    }
    else{
        return -1;
    }
    }
};