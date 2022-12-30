class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &res, vector<vector<int>> &ans,
            int last, int node){
        if(node==last){
            ans.push_back(res);
            return;
        }
        for(auto nbr:adj[node]){
            res.push_back(nbr);
            dfs(adj, res, ans, last, nbr);
            res.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<graph.size(); i++){
            for(auto j:graph[i])
                adj[i].push_back(j);
        }
        int last = graph.size()-1;
        vector<int> res;
        res.push_back(0);
        dfs(adj, res, ans, last, 0);
        return ans;
    }
};