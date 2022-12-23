class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        int i,n=prices.size(),j;
        if(n<=1){return 0;}
        
        vector<int> b(n,0), s(n,0);
        /*
        b[i] is the max profit until i while last action is BUY
        s[i] is the max profit until i while last action is SELL
        */
        b[0] = (-prices[0]);
        b[1] = max(b[0], -prices[1]);
        s[1] = max(s[0], b[0]+prices[1]);
        
        for(i=2;i<n;i++){
            b[i] = max(b[i-1], s[i-2] - prices[i]); //sell on i-2, then buy leaving gap of 1
            s[i] = max(s[i-1], b[i-1] + prices[i]);
        }
        return s[n-1];
    }
};