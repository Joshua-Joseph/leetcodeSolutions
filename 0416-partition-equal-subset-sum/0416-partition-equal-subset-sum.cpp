class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums)
            sum += i;
        if(sum%2!=0)
            return false;
        int target = sum/2;
        vector<bool> prev(target+1, 0);
        vector<bool> dp(target+1, 0);
        prev[0] = true;
        dp[0] = true;
        if(nums[0]<=target)
            prev[nums[0]] = true;
        for(int i=1; i<nums.size(); i++){
            for(int j=1; j<=target; j++){
                bool notTake = prev[j];
                bool take = false;
                if(nums[i]<=j)
                    take = prev[j-nums[i]];
                dp[j] = notTake or take;
            }
            prev = dp;
        }
        return prev[target];
    }
};