class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans = 1;
        unordered_map<int, bool> hash;
        for(auto i:nums){
            hash[i] = true;
        }
        for(auto i:nums){
            if(hash[i-1]==false){
                int j=1;
                while(hash[i+j])
                    j++;
                ans = max(ans, j);
            }
        }
        return ans;
    }
};