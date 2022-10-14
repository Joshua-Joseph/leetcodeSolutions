class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &neighbors, unordered_map<int, vector<int>> &adj,
            unordered_map<int, bool> &vis, int node, int &min){
        vis[node] = true;
        for(auto nbr:neighbors[node]){ // for all neighbors of node check if its visited
            if(!vis[nbr]){ // if not visited check further
                if(find(adj[node].begin(), adj[node].end(), nbr) != adj[node].end()){ // an edge exists from node
                    //to src i.e. this path needs to be reversed
                    min++;
                }
                dfs(neighbors, adj, vis, nbr, min); // call dfs for all unvisited neighbors of node
            }
        }
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int min = 0;
        unordered_map<int, vector<int>> neighbors; // store neighbors of all nodes
        unordered_map<int, vector<int>> adj; // adjacency list
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            neighbors[connections[i][0]].push_back(connections[i][1]);
            neighbors[connections[i][1]].push_back(connections[i][0]);
        }
        unordered_map<int, bool> vis;
        dfs(neighbors, adj, vis, 0, min);
        return min;
    }
};