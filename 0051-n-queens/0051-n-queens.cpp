class Solution {
public:
    void addSolution(vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        vector<string> res;
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++){
                if(board[i][j]==1){
                    s+='Q';
                }
                else{
                    s+='.';
                }
            }
            res.push_back(s);
        }
        ans.push_back(res);
    }
    
    bool noAttack(int row, int col, vector<vector<int>> &board, int n){
        int x = row;
        int y = col;
        
        // checking if any queen in same column
        while(x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
        }
        
        // checking if queens present in left upper diagonal
        x = row;
        y = col;
        while(x>0 && y>0){
            if(board[x-1][y-1]==1){
                return false;
            }
            x--;
            y--;
        }
        
        // checking if queens present in right upper diagonal
        x = row;
        y = col;
        while(x>0 && y<n-1){
            if(board[x-1][y+1]==1){
                return false;
            }
            x--;
            y++;
        }
        
        return true;
    }
    
    void solve(int row, vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        if(row==n){
            addSolution(board, ans, n);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(noAttack(row, i, board, n)){
                board[row][i] = 1;
                solve(row+1, board, ans, n);
                board[row][i] = 0;
            }
        }
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, board, ans, n);
        return ans;
    }
};