class Solution {
public:
    int f(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        if(dp[row][col] != -1) return dp[row][col];

        int m = matrix.size();
        int n = matrix[0].size();

        int right = 0, left = 0, up = 0, down = 0;

        if(col + 1 < n && matrix[row][col+1] > matrix[row][col])
            right = f(row, col+1, matrix,dp);

        if(col - 1 >= 0 && matrix[row][col-1] > matrix[row][col])
            left = f(row, col-1, matrix,dp);

        if(row - 1 >= 0 && matrix[row-1][col] > matrix[row][col])
            up = f(row-1, col, matrix,dp);

        if(row + 1 < m && matrix[row+1][col] > matrix[row][col])
            down = f(row+1, col, matrix,dp);

        return dp[row][col] = 1 + max(max(right,left), max(up,down));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_len = 1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                max_len = max(max_len,f(i,j,matrix,dp));
            }
        }
        return max_len;
    }
};
