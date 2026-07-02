class Solution {
public:
    int f(int row,int col,vector<vector<int>>& dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int left = f(row,col-1,dp);
        int up = f(row-1,col,dp);
        return dp[row][col]=left+up;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,dp);

        // Tabulation
        vector<vector<int>> dp(m,vector<int> (n,0));
        //when col =0 or row =0 means fill them with 1 as there is only one way to reach destination,
        // its either down or right;
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                int left = dp[i][j-1];
                int up = dp[i-1][j];
                dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
    }
};
