class Solution {
public:
    int getMax(vector<int>& nums, int s, int e){
        if(e-s+1==1){
            return nums[s];
        }
        vector<int> dp(e-s+1, 0);
        dp[0] = nums[s];
        dp[1] = max(dp[0], nums[s+1]); // max((dp[i-1]+0), (dp[i-2]+nums[i]))
        for(int i=2; i<e-s+1; i++){
            int inc = dp[i-1] + 0;
            int exc = dp[i-2] + nums[s+i];
            dp[i] = max(inc, exc);
        }
        return dp[dp.size()-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int ans1 = getMax(nums, 0, nums.size()-2);
        int ans2 = getMax(nums, 1, nums.size()-1);
        return max(ans1, ans2);
    }
};