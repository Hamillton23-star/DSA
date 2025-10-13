class Disjointset{
 public:
     vector<int> parent,rank,size;
     Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
         size.resize(n+1,1);

         for(int i=0;i<n;i++){
            parent[i]=i;
         }
     }

     int findparent(int node){
        if(parent[node]==node) return node;

        return parent[node]=findparent(parent[node]);
     }
    
     void unionbyrank(int u,int v){
       int ulp_u=findparent(u);
       int ulp_v=findparent(v);

        if(ulp_u==ulp_v)return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
           parent[ulp_u]=ulp_v;
           rank[ulp_v]++;
        }
     }
  void unionbysize(int u,int v){
       int ulp_u=findparent(u);
       int ulp_v=findparent(v);

        if(ulp_u==ulp_v)return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
           parent[ulp_v]=ulp_u;
           size[ulp_u]+=size[ulp_v];
        }
     }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        Disjointset ds(maxrow+maxcol+2);
        map<int,int> mpp;
        int cnt=0;
        for(auto it : stones){
            int row=it[0];
            int col=it[1]+maxrow+1;
             ds.unionbyrank(row,col);
             mpp[row]=1;
             mpp[col]=1;    
        }
     for(auto it: mpp){
        if(ds.findparent(it.first)==it.first)cnt++;
     }
   return n-cnt;
    }
};