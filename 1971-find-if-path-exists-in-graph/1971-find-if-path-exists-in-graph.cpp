// class Solution {
// public:
//     bool dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &vis, int src, int dest){
//         for(auto nbr:adj[src]){
//             if(nbr==dest)
//                 return true;
//             else{
//                 if(!vis[nbr]){
//                     vis[nbr] = true;
//                     bool found = dfs(adj, vis, nbr, dest);
//                     if(found)
//                         return true;
//                 }
//                 else{
//                     return false;
//                 }
//             }
//         }
//         return false;
//     }
    
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         if(n==1)
//             return true;
//         unordered_map<int, vector<int>> adj;
//         for(int i=0; i<edges.size(); i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         unordered_map<int, bool> vis;
//         if(adj[source].size()==0)
//             return false;
//         vis[source] = true;
//         return dfs(adj, vis, source, destination);
//     }
// };


class Solution {
public:
    int ans=-1;
    void dfs(int node,vector<int> adj[],vector<int>& vis,int destination){
        if(node==destination)ans=1;
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,destination);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        dfs(source,adj,vis,destination);
        if(ans==1)return true;
        return false;
        
    }
};