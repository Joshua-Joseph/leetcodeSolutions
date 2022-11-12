//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool solve(unordered_map<int,vector<int>> &adj, int m, int n, vector<int> col, int ind){
        
        if(ind==n+1){
            return true;
        }
        for(int i=1; i<=m; i++){
            if(isPossible(adj, ind, i, col)){
                
                col[ind] = i;
                if(solve(adj, m, n, col, ind+1)){
                    // cout<<ind<<" "<<i<<endl;
                    return true;
                }
                else{
                    col[ind] = 0;
                }
            }
        }
        
        return false;
    }
    
    bool isPossible(unordered_map<int,vector<int>> &adj, int ind, int color, vector<int> col){
        for(auto nbr:adj[ind]){
            if(col[nbr]==color){
                return false;
            }
        }
        return true;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++){
            adj[i+1];
            for(int j=0; j<n; j++){
                if(graph[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        vector<int> col(n+1, 0);
        return solve(adj, m, n, col, 1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends