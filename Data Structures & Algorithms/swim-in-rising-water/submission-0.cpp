class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int> , vector<vector<int>>,greater<>> pq;
        pq.push({grid[0][0],0,0});
        vector<vector<int>> visited(m,vector<int> (n,0));
        visited[0][0] = 1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int row = curr[1];
            int col = curr[2];
            if(row == m-1 && col == n-1) return time;
            for(int i=0;i<4;++i){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    pq.push({max(time,grid[nrow][ncol]),nrow,ncol});                  
                }
            }
        }
        return -1;
    }
};
