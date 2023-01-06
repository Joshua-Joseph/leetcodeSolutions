class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        int i=0;
        while(i<costs.size() and coins>=costs[i]){
            cnt++;
            coins-=costs[i];
            i++;
        }
        return cnt;
    }
};