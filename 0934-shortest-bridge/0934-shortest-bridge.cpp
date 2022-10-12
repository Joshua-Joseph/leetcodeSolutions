class Solution{
    public:
        int dir[5] = {0, 1, 0, -1, 0};
        void paint(vector<vector<int>>& A, int i, int j, vector<pair<int, int>> &q) {
    if (min(i, j) >= 0 && max(i, j) < A.size() && A[i][j] == 1) {
        A[i][j] = 2;
        q.push_back({i, j});
        for (int d = 0; d < 4; ++d)
            paint(A, i + dir[d], j + dir[d + 1], q);
    }
}
int shortestBridge(vector<vector<int>>& A) {
    vector<pair<int, int>> q;
    for (int i = 0; q.size() == 0 && i < A.size(); ++i)
        for (int j = 0; q.size() == 0 && j < A[0].size(); ++j)
            paint(A, i, j, q);
    while (!q.empty()) {
        vector<pair<int, int>> q1;
        for (auto [i, j] : q) {
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < A.size()) {
                    if (A[x][y] == 1)
                        return A[i][j] - 2;
                    if (A[x][y] == 0) {
                        A[x][y] = A[i][j] + 1;
                        q1.push_back({x, y});
                    }
                }
            }
        }
        swap(q, q1);
    }
    return 0;
}
};


// BFS + DFS

// class Solution {
// public:
//     void dfs(vector<vector<int>> &grid, int i, int j, map<pair<int,int>,bool> &vis, queue<pair<int,int>> &q){
//         vis[{i,j}] = true;
//         q.push({i,j});
//         // UP
//         if(i-1>=0 and grid[i-1][j]==1 and !vis[{i-1,j}]){
//             dfs(grid, i-1, j, vis, q);
//         }
//         // DOWN
//         if(i+1<grid.size() and grid[i+1][j]==1 and !vis[{i+1,j}]){
//             dfs(grid, i+1, j, vis, q);
//         }
//         // LEFT
//         if(j-1>=0 and grid[i][j-1]==1 and !vis[{i,j-1}]){
//             dfs(grid, i, j-1, vis, q);
//         }
//         // RIGHT
//         if(j+1<grid.size() and grid[i][j+1]==1 and !vis[{i,j+1}]){
//             dfs(grid, i, j+1, vis, q);
//         }
//         return;
//     }
    
//     int shortestBridge(vector<vector<int>>& grid) {
//         queue<pair<int,int>> q;
//         map<pair<int,int>,bool> vis;
//         bool found = false;
//         for(int i=0; i<grid.size(); i++){
//             for(int j=0; j<grid.size(); j++){
//                 if(grid[i][j]==1 and !vis[{i,j}]){
//                     dfs(grid, i, j, vis, q);
//                     found = true;
//                     break;
//                 }
//             }
//             if(found){
//                 break;
//             }
//         }
//         int moves = 0;
//         while(!q.empty()){
//             moves+=1;
//             int n = q.size();
//             for(int i=0; i<n; i++){
//                 pair<int, int> p1 = q.front();
//                 q.pop();
//                 int r = p1.first;
//                 int c = p1.second;
//                 // UP
//                 if(r-1>=0){
//                     if(grid[r-1][c]==1 and !vis[{r-1,c}]){
//                         return moves-1;
//                     }
//                     else{
//                         vis[{r-1,c}] = true;
//                         q.push({r-1,c});
//                     }
//                 }
//                 // DOWN
//                 if(r+1<grid.size()){
//                     if(grid[r+1][c]==1 and !vis[{r+1,c}]){
//                         return moves-1;
//                     }
//                     else{
//                         vis[{r+1,c}] = true;
//                         q.push({r+1,c});
//                     }
//                 }
//                 // LEFT
//                 if(c-1>=0){
//                     if(grid[r][c-1]==1 and !vis[{r,c-1}]){
//                         return moves-1;
//                     }
//                     else{
//                         vis[{r,c-1}] = true;
//                         q.push({r,c-1});
//                     }
//                 }
//                 // RIGHT
//                 if(c+1<grid.size()){
//                     if(grid[r][c+1]==1 and !vis[{r,c+1}]){
//                         return moves-1;
//                     }
//                     else{
//                         vis[{r,c+1}] = true;
//                         q.push({r,c+1});
//                     }
//                 }
//             }
//         }
//         return moves-1;
//     }
// };