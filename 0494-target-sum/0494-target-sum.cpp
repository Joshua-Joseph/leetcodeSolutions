class Solution {
public:
    void solve(vector<int>& nums, int ind, int target, int sum, int &ans){
        if(ind==nums.size()){
            if(sum==target)
                ans+=1;
            return;
        }
        solve(nums, ind+1, target, sum+nums[ind], ans);
        solve(nums, ind+1, target, sum-nums[ind], ans);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        solve(nums, 0, target, 0, ans);
        return ans;
    }
};