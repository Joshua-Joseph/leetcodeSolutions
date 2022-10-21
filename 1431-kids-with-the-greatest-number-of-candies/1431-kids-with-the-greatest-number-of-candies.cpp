class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxi = INT_MIN;
        for(auto i:candies){
            maxi = max(i, maxi);
        }
        vector<bool> result(n, 0);
        for(int i=0; i<n; i++){
            if(candies[i]+extraCandies >= maxi){
                result[i]=1;
            }
        }
        return result;
    }
};