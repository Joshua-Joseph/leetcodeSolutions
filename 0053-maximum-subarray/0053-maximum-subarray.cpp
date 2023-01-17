class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> everySum;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans+nums[i], nums[i]);
            everySum.push_back(ans);
        }
        sort(everySum.begin(), everySum.end());
        return everySum[everySum.size()-1];
    }
};