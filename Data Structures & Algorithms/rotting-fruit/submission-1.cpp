class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        //{steps,{row,col}} of the treasure chest
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 2) q.push({0,{i,j}});
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int time = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int steps = node.first;
            time = max(time,steps);
            int row = node.second.first;
            int col = node.second.second;
            for(int i=0;i<4;++i){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                    visited[nrow][ncol]=1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 1 && visited[i][j] != 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
