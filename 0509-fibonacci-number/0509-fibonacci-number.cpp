class Solution {
public:
//     RECURSION
//     int fib(int n) {
        
//         if(n==0){
//             return 0;
//         }
//         if(n==1){
//             return 1;
//         }
        
//         return (fib(n-1) + fib(n-2));
        
//     }
    
//     TOP DOWN DP 
//     int topDown(int n, vector<int> &dp){
//         if(n<=1){
//             return n;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         dp[n] = topDown(n-1, dp) + topDown(n-2, dp);
//         return dp[n];
//     }
    
//     int fib(int n) {
//         vector<int> dp(n+1);
//         for(int i=0; i<=n; i++){
//             dp[i]=-1;
//         }
//         return topDown(n, dp);
//     }
    
//     BOTTOM UP DP 
//     int fib(int n) {
//         vector<int> dp(n+1);
//         if(n<=1){
//             return n;
//         }
//         dp[0]=0;
//         dp[1]=1;
//         for(int i=2; i<=n; i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
    
    // SPACE OPTIMIZATION
    int fib(int n) {
        if(n<=1){
            return n;
        }
        int p1 = 1;
        int p2 = 0;
        int curr;
        for(int i=2; i<=n; i++){
            curr = p1 + p2;
            p2 = p1;
            p1 = curr;
        }
        return curr;
    }
};