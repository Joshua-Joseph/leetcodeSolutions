class Solution {
public:
    
    bool isPossible(vector<vector<char>> &sudoku, int row, int col, char val){
        // check in same row & column
        for(int i=0; i<9; i++){
            if(sudoku[row][i]==val && i!=col){
                return false;
            }
            if(sudoku[i][col]==val && i!=row){
                return false;
            }
        }
        
        // check in same matrix
        for(int i=(row/3)*3; i<((row/3)*3)+3; i++){
            for(int j=(col/3)*3; j<((col/3)*3)+3; j++){
                if(sudoku[i][j] == val && i!=row && j!=col){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &sudoku){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(sudoku[i][j]!='.'){
                    if(isPossible(sudoku, i, j, sudoku[i][j])==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};