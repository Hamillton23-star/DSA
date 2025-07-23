class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                vis[i][j]=1;
                q.push({0,{i,j}});
                }
            }
        }
        
    int dcol[]={1,0,-1,0};
    int drow[]={0,1,0,-1};
    while(!q.empty()){
        auto it=q.front();
        int steps=it.first;
        int row=it.second.first;
        int col=it.second.second;
        q.pop();
        dist[row][col]=steps;
        for(int i=0;i<4;i++){
          int nrow=row+drow[i];
          int ncol=col+dcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
              vis[nrow][ncol]=1;
            q.push({steps+1,{nrow,ncol} });
             }
          }
        }
    return dist;
    }
};