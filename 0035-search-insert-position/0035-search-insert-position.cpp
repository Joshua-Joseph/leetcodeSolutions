class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int m=s+(e-s)/2;
        int ans=m;
        while(s<e){
            if(nums[m]==target){
                ans = m;
                break;
            }
            else if(nums[m]>target){
                e=m-1;
                m=s+(e-s)/2;
                ans=m;
            }
            else{
                s=m+1;
                m=s+(e-s)/2;
                ans=m;
            }
        }
        if(nums[m]==target || nums[m]>target) return ans;
        return ans+1;
    }
};