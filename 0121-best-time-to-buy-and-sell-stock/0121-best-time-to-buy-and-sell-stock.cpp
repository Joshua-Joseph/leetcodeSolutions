class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        int currProfit = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<mini){
                mini = prices[i];
            }
            
            currProfit = prices[i] - mini;
            if(currProfit>profit){
                profit = currProfit;
            }
        }
        
        return profit;
    }
};