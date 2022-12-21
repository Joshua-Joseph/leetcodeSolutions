class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis, int node){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(adj, vis, i);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<rooms.size(); i++){
            for(auto j:rooms[i]){
                adj[i].push_back(j);
            }
        }
        unordered_map<int, bool> vis;
        dfs(adj, vis, 0);
        for(int i=0; i<rooms.size(); i++){
            if(vis[i]!=true)
                return false;
        }
        return true;
    }
};