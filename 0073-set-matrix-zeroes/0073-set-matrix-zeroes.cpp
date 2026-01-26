class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false;
        int p=matrix.size(), q=matrix[0].size();

        for(int row=0; row<p; row++){
            for(int col=0; col<q; col++){
                if(matrix[row][col] == 0){
                    // Set the Column to zero
                    matrix[0][col] = 0;

                    // Avoid Overlapping 1st Row
                    if(row>0){
                        matrix[row][0] = 0;
                    }else{
                        firstRowZero = true;
                    }
                }
            }
        }

        // Skip 1st Row and Col as they hold the flags
        for(int row=1; row<p; row++){
            for(int col=1; col<q; col++){
                if(matrix[0][col] == 0 || matrix[row][0] == 0){
                    matrix[row][col] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int row=1; row<p; row++){
                matrix[row][0] = 0;
            }
        }

        if(firstRowZero){
            for(int col=0; col<q; col++){
                matrix[0][col] = 0;
            }
        }


    }
};