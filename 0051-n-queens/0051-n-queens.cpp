class Solution {
public:
    void solve(vector<vector<string>> &ans, vector<string> &board, vector<bool> &sameCol, 
               vector<bool> &leftDiagonal, vector<bool> rightDiagonal, int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(!sameCol[i] and !leftDiagonal[i+row] and !rightDiagonal[(n-1)+(i-row)]){
                board[row][i]='Q';
                sameCol[i]=true;
                leftDiagonal[i+row]=true;
                rightDiagonal[(n-1)+(i-row)]=true;
                solve(ans, board, sameCol, leftDiagonal, rightDiagonal, row+1, n);
                board[row][i]='.';
                sameCol[i]=false;
                leftDiagonal[i+row]=false;
                rightDiagonal[(n-1)+(i-row)]=false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string res(n, '.');
        vector<string> board(n, res);
        vector<vector<string>> ans;
        vector<bool> sameCol(n, 0);
        vector<bool> leftDiagonal(2*n - 1, 0);
        vector<bool> rightDiagonal(2*n - 1, 0);
        solve(ans, board, sameCol, leftDiagonal, rightDiagonal, 0, n);
        return ans;
    }
};

// class Solution {
// public:
//     void addSolution(vector<vector<int>> &board, vector<vector<string>> &ans, int n){
//         vector<string> res;
//         for(int i=0; i<n; i++){
//             string s = "";
//             for(int j=0; j<n; j++){
//                 if(board[i][j]==1){
//                     s+='Q';
//                 }
//                 else{
//                     s+='.';
//                 }
//             }
//             res.push_back(s);
//         }
//         ans.push_back(res);
//     }
    
//     bool noAttack(int row, int col, vector<vector<int>> &board, int n){
//         int x = row;
//         int y = col;
        
//         // checking if any queen in same column
//         while(x>=0){
//             if(board[x][y]==1){
//                 return false;
//             }
//             x--;
//         }
        
//         // checking if queens present in left upper diagonal
//         x = row;
//         y = col;
//         while(x>0 && y>0){
//             if(board[x-1][y-1]==1){
//                 return false;
//             }
//             x--;
//             y--;
//         }
        
//         // checking if queens present in right upper diagonal
//         x = row;
//         y = col;
//         while(x>0 && y<n-1){
//             if(board[x-1][y+1]==1){
//                 return false;
//             }
//             x--;
//             y++;
//         }
        
//         return true;
//     }
    
//     void solve(int row, vector<vector<int>> &board, vector<vector<string>> &ans, int n){
//         if(row==n){
//             addSolution(board, ans, n);
//             return;
//         }
        
//         for(int i=0; i<n; i++){
//             if(noAttack(row, i, board, n)){
//                 board[row][i] = 1;
//                 solve(row+1, board, ans, n);
//                 board[row][i] = 0;
//             }
//         }
        
        
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<vector<int>> board(n, vector<int>(n, 0));
//         solve(0, board, ans, n);
//         return ans;
//     }
// };