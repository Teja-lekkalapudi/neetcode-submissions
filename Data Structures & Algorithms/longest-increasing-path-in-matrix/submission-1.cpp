class Solution {
public:
    int f(int row,int col,int prev,vector<vector<int>>& matrix){
        if(row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()){
            return 0;
        }
        int right = 0,left=0,up=0,down=0;
        if(prev < matrix[row][col]){
            right = 1 +  f(row,col+1,matrix[row][col],matrix);
            left = 1 + f(row,col-1,matrix[row][col],matrix);
            up = 1 + f(row-1,col,matrix[row][col],matrix);
            down = 1 + f(row+1,col,matrix[row][col],matrix);
        }
        int maxi1 = max(right,left);
        int maxi2 = max(up,down);
        return max(maxi1,maxi2);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_len = 1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                max_len = max(max_len,f(i,j,-1,matrix));
            }
        }
        return max_len;
    }
};
