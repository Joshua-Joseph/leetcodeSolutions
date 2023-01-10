class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for(int i=0; i<triangle.size(); i++){
            vector<int> a (triangle[i].size(), -1);
            dp.push_back(a);
        }
        for(int j=0; j<triangle[triangle.size()-1].size(); j++){
            dp[triangle.size()-1][j] = triangle[triangle.size()-1][j];
        }
        for(int i=triangle.size()-2; i>=0; i--){
            // cout<<i<<" ";
            for(int j=0; j<triangle[i].size(); j++){
                // cout<<j<<" ";
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};