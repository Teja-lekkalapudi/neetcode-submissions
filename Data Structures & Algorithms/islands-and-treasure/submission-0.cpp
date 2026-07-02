class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        //{steps,{row,col}} of the treasure chest
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 0) q.push({1,{i,j}});
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int steps = node.first;
            int row = node.second.first;
            int col = node.second.second;
            for(int i=0;i<4;++i){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == INT_MAX){
                    grid[nrow][ncol] = steps;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
    }
};
