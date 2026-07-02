class Solution {
public:
    void dfs(int row, int col ,vector<vector<char>>& board,vector<vector<int>>& visited){
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        int drow[] = {0,-1,1,0};
        int dcol[] = {1,0,0,-1};
        for(int i=0;i<4;++i){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,board,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i == 0 || i == m-1 || j == 0 || j == n-1 ){
                    if(board[i][j] == 'O'){
                        dfs(i,j,board,visited);
                    }
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
