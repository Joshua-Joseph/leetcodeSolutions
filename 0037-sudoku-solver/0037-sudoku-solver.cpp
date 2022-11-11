class Solution {
public:
    
    bool isPossible(vector<vector<char>> &sudoku, int row, int col, char val){
        // check in same row & column
        for(int i=0; i<9; i++){
            if(sudoku[row][i]==val){
                return false;
            }
            if(sudoku[i][col]==val){
                return false;
            }
        }
        
        // check in same matrix
        for(int i=(row/3)*3; i<((row/3)*3)+3; i++){
            for(int j=(col/3)*3; j<((col/3)*3)+3; j++){
                if(sudoku[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &sudoku){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(sudoku[i][j]=='.'){
                    for(char k='1'; k<='9'; k++){
                        if(isPossible(sudoku, i, j, k)){
                            sudoku[i][j] = k;
                            if(solve(sudoku)){
                                return true;
                            }
                            else{
                                sudoku[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board);
    }
};