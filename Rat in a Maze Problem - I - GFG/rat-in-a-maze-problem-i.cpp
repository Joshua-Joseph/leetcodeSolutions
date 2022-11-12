//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, map<pair<int,int>, bool> &vis, string s,
    vector<string> &ans, int r, int c, int n){
        if(r==n-1 and c==n-1){
            ans.push_back(s);
            return;
        }
        
        //DOWN
        if(r+1<n and m[r+1][c]==1 and !vis[{r+1,c}]){
            // cout<<"D"<<r<<c<<endl;
            s+="D";
            vis[{r+1,c}]=1;
            solve(m, vis, s, ans, r+1, c, n);
            s.pop_back();
            vis[{r+1,c}]=0;
        }
        
        //LEFT
        if(c-1>=0 and m[r][c-1]==1 and !vis[{r,c-1}]){
            // cout<<"L"<<r<<c<<endl;
            s+="L";
            vis[{r,c-1}]=1;
            solve(m, vis, s, ans, r, c-1, n);
            s.pop_back();
            vis[{r,c-1}]=0;
        }
        
        //RIGHT
        if(c+1<n and m[r][c+1]==1 and !vis[{r,c+1}]){
            // cout<<"R"<<r<<c<<endl;
            s+="R";
            vis[{r,c+1}]=1;
            solve(m, vis, s, ans, r, c+1, n);
            s.pop_back();
            vis[{r,c+1}]=0;
        }
        
        //UP
        if(r-1>=0 and m[r-1][c]==1 and !vis[{r-1,c}]){
            // cout<<"U"<<r<<c<<endl;
            s+="U";
            vis[{r-1,c}]=1;
            solve(m, vis, s, ans, r-1, c, n);
            s.pop_back();
            vis[{r-1,c}]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        map<pair<int,int>, bool> vis;
        string s = "";
        vector<string> ans;
        vis[{0,0}]=true;
        if(m[0][0]==0){
            return ans;
        }
        solve(m, vis, s, ans, 0, 0, n);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends