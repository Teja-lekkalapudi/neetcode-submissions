class Solution {
public:
    bool f(int row,int col,string temp,vector<vector<char>>& board,string& word,vector<vector<int>>& visited){
        temp.push_back(board[row][col]);
        visited[row][col] = 1;
        if(temp == word){
            return true;
        }   
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        for(int i=0;i<4;++i){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && !visited[nrow][ncol]){
                
                if(f(nrow,ncol,temp,board,word,visited)) return true;
                              
            }
        } 
        temp.pop_back();
        visited[row][col] = 0;       
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        string temp = "";
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (f(i, j, temp, board, word,visited))
                    return true;
            }
        }
        return false;
    }
};
