class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto i:nums){
            cnt[i]++;
        }
        int ans = 0;
        for(auto i:cnt){
            if(i.second>1){
                ans = i.first;
                break;
            }    
        }
        return ans;
    }
};