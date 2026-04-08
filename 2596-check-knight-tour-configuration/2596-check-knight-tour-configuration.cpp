class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int expValue){
        int n = grid.size();
        // check if row or col is out of bounds
        if(row<0 || col<0 || row>=n || col>=n || grid[row][col] != expValue){
            return false;
        }

        if(expValue == n*n-1){
            return true;
        }

        //Check all possible row and column location
        bool ans1 = isValid(grid, row-2, col+1, expValue+1);
        bool ans2 = isValid(grid, row-1, col+2, expValue+1);
        bool ans3 = isValid(grid, row+1, col+2, expValue+1);
        bool ans4 = isValid(grid, row+2, col+1, expValue+1);
        bool ans5 = isValid(grid, row+2, col-1, expValue+1);
        bool ans6 = isValid(grid, row+1, col-2, expValue+1);
        bool ans7 = isValid(grid, row-1, col-2, expValue+1);
        bool ans8 = isValid(grid, row-2, col-1, expValue+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, 0);
    }
};