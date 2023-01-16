class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto i:nums){
            cnt[i]++;
        }
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(cnt[j]==0){
                while(j<2 and cnt[j]==0){
                    j++;
                }
            }
            nums[i] = j;
            cnt[j]--;
        }
    }
};