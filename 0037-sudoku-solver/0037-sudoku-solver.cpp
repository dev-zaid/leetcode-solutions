class Solution {
public:
    bool isAllowed(vector<vector<char>>& board, int row,int col, char dig){
        // check row
        for(int i=0; i<9; i++){
            if(board[row][i] == dig){
                return false;
            }
        }

        // check col
        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        //check grid
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for(int i=startRow; i <= startRow+2; i++){
            for(int j=startCol; j <= startCol+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board, int row,int col) {
        if(row==9){
            return true;
        }

        int nextCol= col+1;
        int nextRow = row;
        if(nextCol==9){
            nextRow=row+1;
            nextCol=0;
        }

        if(board[row][col] != '.'){
            return sudokuSolver(board, nextRow, nextCol);
        }

        for(char dig='1'; dig<='9'; dig++){
            if(isAllowed(board, row, col, dig)){
                board[row][col] = dig;
                if(sudokuSolver(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.';
            }
            
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }
};