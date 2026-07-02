class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,queue<pair<int,int>>& q,vector<vector<int>>& visited){
        q.push({row,col});
        int m = grid.size();
        int n = grid[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(int i=0;i<4;++i){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        //Do bfs,in four directions.
        //visited should be 2D.
        //{row,col}
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        //Initialise visited with 0
        vector<vector<int>> visited(m,vector<int>(n,0));
        int count = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(i,j,grid,q,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
