class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        vector<int> ans;
        n = n/3;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-n; i++){
            if(nums[i]==nums[i+n]){
                s.insert(nums[i]);
            }
        }
        for(auto it = s.begin(); it!=s.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};