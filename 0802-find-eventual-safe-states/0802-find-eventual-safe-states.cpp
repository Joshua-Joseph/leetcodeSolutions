class Solution {
public: 
    void dfs(vector<vector<int>>& graph, int i, 
             unordered_map<int, bool> &vis, unordered_map<int, bool> &safe){
        vis[i]=true;
        if(graph[i].size()==0){
            safe[i]=true;
            return;
        }
        for(auto nbr:graph[i]){
            if(!vis[nbr]){
                dfs(graph, nbr, vis, safe);
            }
            if(!safe[nbr]){
                safe[i]=false;
                return;
            }
        }
        safe[i]=true;
        return;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        unordered_map<int, bool> vis;
        unordered_map<int, bool> safe;
        // unordered_map<int, vector<int>> adj;
        // for(int i=0; i<graph.size(); i++){
        //     for(auto num : graph[i]){
        //         adj[i].push_back(num);
        //     }
        // }
        for(int i=0; i<graph.size(); i++){
            if(!vis[i]){
                dfs(graph, i, vis, safe);
            }
        }
        for(auto i:safe){
            if(i.second){
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};