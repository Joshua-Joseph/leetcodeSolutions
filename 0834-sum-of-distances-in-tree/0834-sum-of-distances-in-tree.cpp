class Solution {
    int solve(int source,vector<int> adj_list[],int &n){
        vector<bool> visited(n,0);
        queue<pair<int,int>> q;
        q.push({source,0});
        visited[source]=1;
        int ans=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int node=q.front().first;
                int lvl=q.front().second;
                q.pop();
                ans+=lvl;
                for(auto i:adj_list[node]){
                    if(!visited[i]){
                        visited[i]=1;
                        q.push({i,lvl+1});
                    }
                }

            }
            
        }
        return ans;
        
    }
    int dfs_children(int index,vector<int> adj_list[],vector<bool> &visited,vector<int> &children){
        int ans=1;
        visited[index]=1;

        for(auto i:adj_list[index]){
            if(!visited[i]){
                ans+=dfs_children(i,adj_list,visited,children);
            }
        }
        return children[index]=ans;
    }
    void dfs(int index,vector<int> adj_list[],vector<bool> &visited,vector<int> &children,vector<int> &ans,int &n){
        visited[index]=1;
        for(auto i:adj_list[index]){
            if(!visited[i]){
                ans[i] =ans[index]-(2*children[i]) + n;
                dfs(i,adj_list,visited,children,ans,n);

            }
        }


    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges){ 
        vector<int> adj_list[n];
        for(auto i:edges){
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }

        vector<int> children(n,0);
        vector<bool> visited(n,0);
        children[0]=dfs_children(0,adj_list,visited,children);
        //finding ans for zero
        vector<int> ans(n,-1);
        ans[0]=solve(0,adj_list,n);

        vector<bool> visited2(n,0);
        dfs(0,adj_list,visited2,children,ans,n);

        


        
        return ans;
        
    }
};