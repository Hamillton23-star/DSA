class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int count=0;
       queue<pair<int,pair<int,int>>> q;
       vector<vector<int>> vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
            }
            else if(grid[i][j]==2){
             q.push({0,{i,j}});
            }
        }
       } 
       int tm=0;
       int delrow[]={0,-1,0,1};
      int delcol[]={-1,0,1,0};
      while(!q.empty()){
        int time=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
         
         for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
         int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
        grid[nrow][ncol]=2;
        count--;
        
        tm=max(time+1,tm);
        if(count==0)break;
        q.push({time+1,{nrow,ncol}});
        }
         }
      }
       return (count==0) ? tm: -1;
    }
};