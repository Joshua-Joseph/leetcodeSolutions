class Solution {
public:
//     // Return false when cycle is found
// bool DFS(int source, vector<bool> &visited, vector<bool> &currVisited, vector<vector<int>>& graph, vector<bool> &safe){
// 	visited[source] = true;
// 	currVisited[source] = true;

// 	// Explore adj vertices
// 	for(auto adj: graph[source]){
// 		if(visited[adj] == false){
// 			// if cycle exists w.r.t adj vertex then false is returned
// 			if(DFS(adj, visited, currVisited, graph, safe) == false){
// 				return safe[source] = false;
// 			}
// 		}
// 		// if the vertex is visited already and it is currently in the previous DFS calls 
// 		else if(visited[adj] == true && currVisited[adj] == true){
// 			// Cycle exists
// 			// Hence cannot reach terminal node thus return false
// 			return safe[source] = false;
// 		}
// 	}
// 	// As adj vertices of source are explored, make currVisited as false because we are coming out of its DFS call
// 	currVisited[source] = false;
// 	return safe[source];
// }

// vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
// 	int vertices = graph.size();

// 	// visited stores true for all the vertices that are visited 
// 	vector<bool> visited(vertices, false);

// 	// currentVisited stores true for the vertices that are currently in DFS call
// 	vector<bool> currVisited(vertices, false);

// 	// Intially, all vertices are considered as safe nodes
// 	vector<bool> safe(vertices, true);

// 	for(int i=0; i<vertices; i++){
// 		if(visited[i] == false){
// 			DFS(i, visited, currVisited, graph, safe);
// 		}
// 	}
// 	vector<int> ans;
// 	for(int i=0; i<vertices; i++){
// 		if(safe[i])
// 			ans.push_back(i);
// 	}
// 	return ans;
// }
    
    
    void dfs(unordered_map<int, vector<int>> &adj, int i, 
             unordered_map<int, bool> &vis, unordered_map<int, bool> &safe){
        vis[i]=true;
        if(adj[i].size()==0){
            safe[i]=true;
            return;
        }
        for(auto nbr:adj[i]){
            if(!vis[nbr]){
                dfs(adj, nbr, vis, safe);
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
        unordered_map<int, bool> cur;
        unordered_map<int, bool> safe;
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<graph.size(); i++){
            for(auto num : graph[i]){
                adj[i].push_back(num);
            }
        }
        for(int i=0; i<graph.size(); i++){
            if(!vis[i]){
                dfs(adj, i, vis, safe);
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