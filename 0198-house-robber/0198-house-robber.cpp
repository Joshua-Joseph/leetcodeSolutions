class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        // vector<int> dp(nums.size(), 0);
        // dp[0] = nums[0];
        // dp[1] = max(dp[0], nums[1]); // max((dp[i-1]+0), (dp[i-2]+nums[i]))
        // for(int i=2; i<nums.size(); i++){
        //     int inc = dp[i-1] + 0;
        //     int exc = dp[i-2] + nums[i];
        //     dp[i] = max(inc, exc);
        // }
        // return dp[nums.size()-1];
        int prev2 = nums[0];
        int prev1 = max(prev2, nums[1]);
        for(int i=2; i<nums.size(); i++){
            int inc = prev1 + 0;
            int exc = prev2 + nums[i];
            int ans = max(inc, exc);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};