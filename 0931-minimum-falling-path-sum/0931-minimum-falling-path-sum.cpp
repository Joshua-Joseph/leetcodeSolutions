class Solution {
public:
    // DP
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col){
        if(row==matrix.size()){
            return 0;
        }
        else if(col<0 || col==matrix.size()){
            return 10000000;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans1 = dfs(matrix, dp, row+1, col-1) + matrix[row][col];
        int ans2 = dfs(matrix, dp, row+1, col) + matrix[row][col];
        int ans3 = dfs(matrix, dp, row+1, col+1) + matrix[row][col];
        dp[row][col] = min(ans1, min(ans2, ans3));
        return dp[row][col];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int mini = INT_MAX;
        for(int i=0; i<matrix[0].size(); i++){
            mini = min(mini, dfs(matrix, dp, 0, i));
        }
        return mini;
    }
};

// RECURSIVE SOLUTION


// void dfs(vector<vector<int>>& matrix, int &mini, int row, int col, int temp){
//         if(row==matrix.size()){
//             mini = min(mini, temp);
//             return;
//         }
//         else if(col<0 || col==matrix.size()){
//             return;
//         }
//         temp+=matrix[row][col];
//         dfs(matrix, mini, row+1, col-1, temp);
//         dfs(matrix, mini, row+1, col, temp);
//         dfs(matrix, mini, row+1, col+1, temp);
//         temp-=matrix[row][col];
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int mini = INT_MAX;
//         for(int i=0; i<matrix[0].size(); i++){
//             int temp = 0;
//             dfs(matrix, mini, 0, i, temp);
//         }
//         return mini;
//     }


// GREEDY SOLUTION

// int minFallingPathSum(vector<vector<int>>& matrix) {
//         int mini = INT_MAX;
//         int sum = 0;
//         int ind = -1;
//         for(int i=0; i<matrix[0].size(); i++){
//             if(matrix[0][i]<mini){
//                 ind = i;
//                 mini = matrix[0][i];
//             }
//         }
//         sum+=mini;
//         for(int i=1; i<matrix.size(); i++){
//             int mini2 = INT_MAX;
//             for(int j=ind-1; j<ind+2; j++){
//                 if(j>=0 && j<matrix[0].size()){
//                     if(matrix[i][j]<mini2){
//                         ind = j;
//                         mini2 = matrix[i][j];
//                     }
//                 }
//             }
//             sum+=mini2;
//         }
//         return sum;
//     }