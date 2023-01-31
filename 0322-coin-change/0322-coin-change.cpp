class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int cnt = 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, INT_MAX));
        if(coins[0]<=amount)
            dp[0][coins[0]] = 0;
        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }
        for(int i=1; i<=amount; i++){
            int t1 = INT_MAX;
            if(i>=coins[0]){
                t1 = dp[0][i-coins[0]];
                if(t1!=INT_MAX) t1+=1;
            }
            dp[0][i] = t1;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                int nt = dp[i-1][j];
                int t1 = INT_MAX;
                int t2 = INT_MAX;
                if(j>=coins[i]){
                    t1 = dp[i][j-coins[i]];
                    if(t1!=INT_MAX) t1+=1;
                } 
                if(j>=coins[i]){
                    t2 = dp[i-1][j-coins[i]];
                    if(t2!=INT_MAX) t2+=1;
                }
                dp[i][j] = min(nt, min(t1,t2));
            }
        }
        int ans = dp[n-1][amount];
        if(ans==INT_MAX) return -1;
        return ans;
    }
};



// MEMOIZATION
// class Solution {
// public:
//     int f(vector<int>& coins, int i, int amt, int cnt, vector<vector<int>> &dp){
//         if(i<0){
//             if(amt!=0) return INT_MAX;
//         }
//         if(amt==0) return 0;
//         if(dp[i][amt]!=-1) return dp[i][amt];
//         int nt = f(coins, i-1, amt, cnt, dp);
//         int t1 = INT_MAX;
//         int t2 = INT_MAX;
//         if(amt>=coins[i]){
//             t1 = f(coins, i, amt-coins[i], cnt, dp);
//             if(t1!=INT_MAX) t1+=1;
//         } 
//         if(amt>=coins[i]){
//             t2 = f(coins, i-1, amt-coins[i], cnt, dp);
//             if(t2!=INT_MAX) t2+=1;
//         } 
//         return dp[i][amt] = min(nt, min(t1,t2));
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         int cnt = 0;
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, -1));
//         int ans = f(coins, n-1, amount, cnt, dp);
//         if(ans==INT_MAX) return -1;
//         return ans;
//     }
// };


// RECURSION
// class Solution {
// public:
//     int f(vector<int>& coins, int i, int amt, int cnt){
//         if(i<0){
//             if(amt!=0) return INT_MAX;
//         }
//         if(amt==0) return 0;
//         int nt = f(coins, i-1, amt, cnt);
//         int t1 = INT_MAX;
//         int t2 = INT_MAX;
//         if(amt>=coins[i]){
//             t1 = f(coins, i, amt-coins[i], cnt);
//             if(t1!=INT_MAX) t1+=1;
//         } 
//         if(amt>=coins[i]){
//             t2 = f(coins, i-1, amt-coins[i], cnt);
//             if(t2!=INT_MAX) t2+=1;
//         } 
//         return min(nt, min(t1,t2));
//     }
    
//     int coinChange(vector<int>& coins, int amount) {
//         int cnt = 0;
//         int n = coins.size();
//         int ans = f(coins, n-1, amount, cnt);
//         if(ans==INT_MAX) return -1;
//         return ans;
//     }
// };