class Solution {
public:
    int findParent(vector<int> &parent, int node){
        while(parent[node] != node){
            parent[node] = parent[parent[node]]; // path compression
            node = parent[node];
        }
        return node;
    }
    
    void doUnion(vector<int> &rank, int n1, int n2, vector<int> &parent){
        int p1 = findParent(parent, n1);
        int p2 = findParent(parent, n2);
        if(rank[p1]==rank[p2]){
                rank[p1]++;
                parent[p2] = p1;   
        }
        else if(rank[p1]>rank[p2]){
            parent[p2] = p1;
        }
        else{
            parent[p1] = p2;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> parent;
        vector<int> rank;
        for(int i=0; i<=edges.size(); i++){
            parent.push_back(i);
            rank.push_back(0);
        }
        for(int i=0; i<edges.size(); i++){
            if(findParent(parent, edges[i][0]) == findParent(parent, edges[i][1])){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
            else{
                doUnion(rank, edges[i][0], edges[i][1], parent);
            }
        }
        return ans;
    }
};