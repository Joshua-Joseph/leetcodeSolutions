class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int great = nums[nums.size()-1];
        int small = nums[0];
        int ans = 1;
        for(int i=small; i>=1; i--){
            if(great%i==0 && small%i==0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};