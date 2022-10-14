class Solution {
public:
    //simple dfs traversal
    void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis,
            int node){
        vis[node] = true;
        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                dfs(adj, vis, nbr);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        unordered_map<int, vector<int>> adj;
        int m = grid.size();//rows
        int n = grid[0].size();//cols
        int cnt = 0;
        // create an adjacency list based on the matrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cnt++;
                if(grid[i][j]=='1'){
                    adj[cnt];
                    //UP
                    if((i-1)>=0 and grid[i-1][j]=='1'){
                        adj[cnt].push_back(cnt-n);
                    }
                    //DOWN
                    if((i+1)<m and grid[i+1][j]=='1'){
                        adj[cnt].push_back(cnt+n);
                    }
                    //RIGHT
                    if((j+1)<n and grid[i][j+1]=='1'){
                        adj[cnt].push_back(cnt+1);
                    }
                    //LEFT
                    if((j-1)>=0 and grid[i][j-1]=='1'){
                        adj[cnt].push_back(cnt-1);
                    }
                }
            }
        }
        // adj list done
        int ans=0;
        unordered_map<int, bool> vis;
        // call dfs for every disconnected components
        for(int i=1; i<=m*n; i++){
            if(adj.find(i) != adj.end() and !vis[i]){
                ans++;
                dfs(adj, vis, i);
            }
        }
        return ans;
    }
};