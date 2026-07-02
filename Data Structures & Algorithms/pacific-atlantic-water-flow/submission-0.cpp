class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited){
        visited[r][c] = true;

        for(auto &d : directions){
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr>=0 && nr<m && nc>=0 && nc<n &&
               !visited[nr][nc] &&
               heights[nr][nc] >= heights[r][c]){
                dfs(heights, nr, nc, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific borders
        for(int i=0;i<m;i++) dfs(heights, i, 0, pac);      // left column
        for(int j=0;j<n;j++) dfs(heights, 0, j, pac);      // top row

        // Atlantic borders
        for(int i=0;i<m;i++) dfs(heights, i, n-1, atl);    // right column
        for(int j=0;j<n;j++) dfs(heights, m-1, j, atl);    // bottom row

        vector<vector<int>> res;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }

        return res;
    }
};
