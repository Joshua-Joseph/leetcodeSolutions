class Solution {
public:
    void reverse(vector<int>& nums, int s, int e){
        while(s<e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int ind1 = nums.size();
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind1 = i;
                break;
            }
        }
        if(ind1==nums.size()){
            reverse(nums, 0, nums.size()-1);
            return;
        }
        for(int i=nums.size()-1; i>ind1; i--){
            if(nums[i]>nums[ind1]){
                swap(nums[i], nums[ind1]);
                break;
            }
        }
        reverse(nums, ind1+1, nums.size()-1);
        return;
    }
};