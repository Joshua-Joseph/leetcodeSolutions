class Solution {
public:
    int f(vector<int>& coins, int i, int amt, int cnt, vector<vector<int>> &dp){
        if(i<0){
            if(amt!=0) return INT_MAX;
        }
        if(amt==0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int nt = f(coins, i-1, amt, cnt, dp);
        int t1 = INT_MAX;
        int t2 = INT_MAX;
        if(amt>=coins[i]){
            t1 = f(coins, i, amt-coins[i], cnt, dp);
            if(t1!=INT_MAX) t1+=1;
        } 
        if(amt>=coins[i]){
            t2 = f(coins, i-1, amt-coins[i], cnt, dp);
            if(t2!=INT_MAX) t2+=1;
        } 
        return dp[i][amt] = min(nt, min(t1,t2));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int cnt = 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(coins, n-1, amount, cnt, dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};