class Solution {
public:
    bool check(int nd,vector<int>adj[],vector<int>&color)
    {
        queue<int>q;
        q.push(nd);
        
        color[nd]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it;
                if(color[adjnode]==-1)
                {
                    color[adjnode]=!color[node];
                    q.push(adjnode);
                }
                else if(color[adjnode]==color[node])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            int u=dislikes[i][0];
            int v=dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(check(i,adj,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};