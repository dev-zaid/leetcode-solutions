class Solution {
public:
    int ROWS, COLS;
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size(), COLS = board[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
        
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int ch){
        if(word.length() == ch){
            return true;
        }
        
        if (row < 0 || col < 0 || row >= ROWS || col >= COLS || word[ch] != board[row][col] || visited[row][col]){
            return false;
        }

        visited[row][col] = true;

        bool res = dfs(board, word, row-1, col, ch+1) || dfs(board, word, row+1, col, ch+1) || dfs(board, word, row, col-1, ch+1) || dfs(board, word, row, col+1, ch+1);

        visited[row][col] = false;

        return res;
    }
};