class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp( obstacleGrid.size() , vector<int> (obstacleGrid[0].size(), 0));
        if(obstacleGrid[0][0]!=1)
            dp[0][0] = 1;
        for(int i=0; i<obstacleGrid.size(); i++){
            for(int j=0; j<obstacleGrid[i].size(); j++){
                if(i==0 and j==0)
                    continue;
                int up = 0;
                int left = 0;
                if(j-1>=0 and obstacleGrid[i][j]!=1)
                    left = dp[i][j-1];
                if(i-1>=0 and obstacleGrid[i][j]!=1)
                    up = dp[i-1][j];
                dp[i][j] = up+left;
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};