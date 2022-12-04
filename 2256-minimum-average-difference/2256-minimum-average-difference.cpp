class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum = 0;
        for(auto i:nums){
            sum+=i;
        }
        vector<int> ans(nums.size(), 0);
        long long int left = 0;
        long long int mini = INT_MAX;
        int ind = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            left+=nums[i];
            sum-=nums[i];
            if(sum==0){
                ans[i] = (left)/(i+1);
            }
            else{
                ans[i] = abs((left)/(i+1) - (sum)/(n-i-1));
            }
            if(ans[i]<mini){
                mini = ans[i];
                ind = i;
            }
        }
        return ind;
    }
};